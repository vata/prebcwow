/* 
 * Copyright (C) 2006 CrFusion Team
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#include "StdAfx.h"

void
WorldSession::HandleMessagechatOpcode( WorldPacket & recv_data )
{
    WorldPacket data;

    sLog.outDebug("CHAT: packet received");

    uint32 type;
    uint32 lang;

    recv_data >> type;
    recv_data >> lang;
    switch(type)
    {
        case CHAT_MSG_SAY:
		{
			std::string msg, t;
            recv_data >> msg;

			t = msg;
            if (sChatHandler.ParseCommands (t.c_str(), this) > 0)
				break;
			// If you want universal chatting use this instead of following line
            //sChatHandler.FillMessageData( &data, this, type, LANG_UNIVERSAL, NULL, msg.c_str() );
			sChatHandler.FillMessageData( &data, this, CHAT_MSG_SAY, lang, NULL, msg.c_str() );
            GetPlayer()->SendMessageToSet( &data, true );
			sLog.outChat(lang, GetPlayer()->GetName(), "Say", msg.c_str());
        } break;
        
		case CHAT_MSG_CHANNEL:
		{
            std::string channel, msg, t;
            recv_data >> channel;
            recv_data >> msg;

			t = msg;
			if (sChatHandler.ParseCommands (t.c_str(), this) > 0)
				break;

			Channel *chn = channelmgr.GetChannel(channel.c_str(),GetPlayer());
			if(chn) chn->Say (GetPlayer(), msg.c_str());
			sLog.outChat(lang, GetPlayer()->GetName(), channel.c_str(), msg.c_str());
        } break;

		case CHAT_MSG_WHISPER: 
        {
            std::string to, msg, t;
            recv_data >> to >> msg;

			t = msg;
			if (sChatHandler.ParseCommands (t.c_str(), this) > 0)
				break;

            Player *player = objmgr.GetPlayer(to.c_str());            
			if (!player)
			{
                data.clear();
                //sChatHandler.FillSystemMessageData( &data, this, msg.c_str() );
                //SendPacket(&data);
				this->SystemMessage ("Player '%s' isn't online", to.c_str());
				sLog.outDebug ("ChatHandler.Whisper: Player '%s' isn't online", to.c_str());
                break;
            }

			// Send whisper MSG to receiver
			sChatHandler.FillMessageData(&data, this, type, lang, NULL, msg.c_str());
			player->GetSession()->SendPacket(&data);

			// Echo whisper back to sender
			sChatHandler.FillMessageData(&data, this, CHAT_MSG_WHISPER_INFORM, lang, NULL,
				msg.c_str(), player->GetGUID());
			SendPacket(&data);
			sLog.outChat(lang, GetPlayer()->GetName(), "Wh", msg.c_str());
        } break;

		case CHAT_MSG_YELL:
        {
            std::string msg;
            recv_data >> msg;
            sChatHandler.FillMessageData(&data, this, type, lang, NULL, msg.c_str() );
            SendPacket(&data);
			GetPlayer()->SendMessageToSet( &data, false );
			sLog.outChat(lang, GetPlayer()->GetName(), "Yell", msg.c_str());
        } break;

		case CHAT_MSG_EMOTE:
		{
			std::string msg;
			recv_data >> msg;
			sChatHandler.FillMessageData(&data, this, type, lang, NULL, msg.c_str() );
			SendPacket(&data);
			GetPlayer()->SendMessageToSet( &data, false );
		} break;

		case CHAT_MSG_PARTY:
        {
            std::string msg;
            recv_data >> msg;
            if (sChatHandler.ParseCommands(msg.c_str(), this) > 0)
                break;
            if (GetPlayer()->IsInGroup())
            {
                Group *group = objmgr.GetGroupByLeader(GetPlayer()->GetGroupLeader());
                if (group)
                    group->BroadcastToGroup(this, msg);
            }
			sLog.outChat(lang, GetPlayer()->GetName(), "Party", msg.c_str());
        }

		case CHAT_MSG_GUILD:
        {
            std::string msg;
            recv_data >> msg;
            if (sChatHandler.ParseCommands(msg.c_str(), this) > 0)
                break;
			if (GetPlayer()->GetGuildId() > 0)
            {
				Guild *guild = objmgr.GetGuildById(GetPlayer()->GetGuildId());
                if (guild)
					guild->BroadcastToGuild(this, msg);
            }
			sLog.outChat(lang, GetPlayer()->GetName(), "Guild", msg.c_str());
        }

		case CHAT_MSG_AFK:
		{
			//TODO: Working AFK State
			GetPlayer()->ToggleAFK();
			if(GetPlayer()->HasFlag(PLAYER_FLAGS, PLAYER_FLAG_AFK))
				GetPlayer()->RemoveFlag(PLAYER_FLAGS, PLAYER_FLAG_AFK);
			else
				GetPlayer()->SetFlag(PLAYER_FLAGS, PLAYER_FLAG_AFK);

		} break;

		case CHAT_MSG_DND:
		{
			//TODO: Working DND State
			GetPlayer()->ToggleAFK();
			if(GetPlayer()->HasFlag(PLAYER_FLAGS, PLAYER_FLAG_AFK))
				GetPlayer()->RemoveFlag(PLAYER_FLAGS, PLAYER_FLAG_AFK);
			else
				GetPlayer()->SetFlag(PLAYER_FLAGS, PLAYER_FLAG_AFK);
		} break;

		default:
            sLog.outError("CHAT: unknown msg type %u, lang: %u", type, lang);
    }
}

void
WorldSession::HandleTextEmoteOpcode( WorldPacket & recv_data )
{
	WorldPacket data, data2;
    uint64 guid;
    uint32
		text_emote,
		emote_anim,
		namelen =1;
	Player
		*aPlayer =GetPlayer(),
		*cPlayer =NULL;
	const char *name = " ";

    recv_data >> text_emote;
    recv_data >> guid;

	EmoteEntry *em = sEmoteStore.LookupEntry(text_emote);
	emote_anim = em->emoteId;

	Player* pChar = objmgr.GetObject<Player> (guid); //center->GetSelection());
	if(pChar)
	{
		name = pChar->GetName();
		namelen = strlen(name) + 1;
	} else {
		Creature *pCreature = objmgr.GetObject<Creature>(guid); //center->GetSelection());
		if(pCreature){
			name = pCreature->GetName();
			namelen = strlen(name) + 1;
		}
	}

	data.Initialize(SMSG_EMOTE);
	data << (uint32)emote_anim;
	data << aPlayer->GetGUID();

	data2.Initialize(SMSG_TEXT_EMOTE);
	data2 << aPlayer->GetGUID();
	data2 << (uint32)text_emote;
	data2 << uint32(0);
	data2 << (uint32)namelen;
    if( namelen > 1 )
		data2.append(name, namelen);
    else
		data2 << (uint8)0x00;

	for(PlayerRangeIter itr ((Object*)aPlayer); cPlayer = itr.Advance(); )
	{
		if(cPlayer != aPlayer)
			cPlayer->GetSession()->SendPacket(&data);
		cPlayer->GetSession()->SendPacket(&data2);
	}
}

