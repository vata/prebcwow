#ifndef SERVER_LANGUAGE_H
#define SERVER_LANGUAGE_H

#define TOTHESTR(n) #n

/*********************************
 ** Phrases li�es aux commandes **
 *********************************/
#define MAKEMODGSTR(a) "Tu as r�gl� l" TOTHESTR(a) " de %s sur %i/%i."
#define MAKEMODRSTR(a) "%s a r�gl� t" TOTHESTR(a) " sur %i/%i."
#define MAKESMODGSTR(a) "Tu as r�gl� la vitesse de " TOTHESTR(a) " de %s sur %2.2f."
#define MAKESMODRSTR(a) "%s a r�gl� ta vitesse de " TOTHESTR(a) " sur %2.2f."

#	define LANG_CMD_MOD_HEALTH MAKEMODGSTR(a Vie)
#	define LANG_CMD_MOD_HEALTHR MAKEMODRSTR(a Vie)
#	define LANG_CMD_MOD_MANA MAKEMODGSTR(e Mana)
#	define LANG_CMD_MOD_MANAR MAKEMODRSTR(on Mana)
#	define LANG_CMD_MOD_ENER MAKEMODGSTR('Energie)
#	define LANG_CMD_MOD_ENERR MAKEMODRSTR(on Energie)
#	define LANG_CMD_MOD_RAGE MAKEMODGSTR(a Rage)
#	define LANG_CMD_MOD_RAGER MAKEMODRSTR(a Rage)
#	define LANG_CMD_MOD_LVL MAKEMODGSTR(e Niveau)
#	define LANG_CMD_MOD_LVLR MAKEMODRSTR(on Niveau)
#	define LANG_CMD_MOD_SPEED_INCVAL "Valeur incorrecte pour la vitesse (intervalle accept�e: 1..128)."
#	define LANG_CMD_MOD_SPEED_G MAKESMODGSTR(mouvement)
#	define LANG_CMD_MOD_SPEED_R MAKESMODRSTR(mouvement)
#	define LANG_CMD_MOD_SWIM_G MAKESMODGSTR(nage)
#	define LANG_CMD_MOD_SWIM_R MAKESMODRSTR(nage)
#	define LANG_CMD_MOD_SIZE_G "Tu as r�gl� la taille de %s sur %2.2f."
#	define LANG_CMD_MOD_SIZE_R "%s a r�gl� ta taille sur %2.2f."
#	define LANG_CMD_MOD_MOUNT_G "Tu as donn� une monture � %s."
#	define LANG_CMD_MOD_MOUNT_R "%s t'as donn� une monture."
#	define LANG_CMD_MOD_TALLMONEY_G "You took all money from %s (%d copper)."
#	define LANG_CMD_MOD_TALLMONEY_R "%s took all of your money (%d copper)."
#	define LANG_CMD_MOD_TMONEY_G "Tu prends %i cuivres � %s."
#	define LANG_CMD_MOD_TMONEY_R "%s t'as pris %i cuivres."
#	define LANG_CMD_MOD_GMONEY_G "Tu as donn� %i cuivres � %s."
#	define LANG_CMD_MOD_GMONEY_R "%s t'as donn� %i cuivres."
#	define LANG_CMD_MOD_SPELL_INCS "You should select player to teach spell."
#	define LANG_CMD_MOD_SPELL_ALRD "Can't teach already known spell %d"
#	define LANG_CMD_MOD_SPELL_INCU "Can't unlearn unknown spell %d"
#	define LANG_CMD_MOD_SPELL_OKU "Unlearned spell %d"

#	define LANG_CMD_NPC_SIZE_INC "Taille incorrecte, doit �tre entre 0.01 et 128."
#	define LANG_CMD_NPC_SIZE_G "Taille du PNJ r�gl�e sur %3.2f."
#	define LANG_CMD_NPC_INFO "PNJ S�lectionn� GUID=%X, Entr�e=%d, Lvl=%d, Taille=%.2f, "\
		"TypeMov=%d, Faction=%d, NPCFlags=%X, Model=%d, Monture=%d, SpawnTime=%d..%d sec, "\
		"SpawnDist=%.1f m"
#	define LANG_CMD_NPC_INFOL "Emplacement: map=%d, X=%.1f, Y=%.1f, Z=%.1f"
#	define LANG_CMD_NPC_GUID "Guid du PNJ: lowpart=%u, highpart=%X"
#	define LANG_CMD_NPC_NOSP "Impossible de Spawner la cr�ature %d, ce template n'existe pas."
#	define LANG_CMD_NPC_MTYPE_INC "Valeur incorrecte, utiliser 0-hazard, 1-marche avant, 2-marche arri�re, 3-boucle avant, 4-boucle arri�re"
#	define LANG_CMD_NPC_MTYPE_SVD "Nouveau type de mouvement %d sauvegard�."
#	define LANG_CMD_NPC_RUN_V "Valeur incorrecte, utiliser 0 ou 1."
#	define LANG_CMD_NPC_RUN "Status de course de la cr�ature r�gl� sur %d."
#	define LANG_CMD_NPC_SPTIME_INC "Valeur incorrecte pour un param�tre, utilises une valeur entre 1 seconde et 1 million de secondes."
#	define LANG_CMD_NPC_SPTIME_CR "Temps de Spawn chang� pour %d..%d, timer de respawn R.a.Z."
#	define LANG_CMD_NPC_SPTIME_CH "Temps de Spawn chang� pour %d..%d."
#	define LANG_CMD_NPC_SPDIST_INC "Mauvaise distance, utilises une valeur entre 0 et 100 ou change le type de d�placement du PNJ."
#	define LANG_CMD_NPC_SPDIST_CH "Distance au Spawn de la Cr�ature chang�e pour %.1f m"

#	define LANG_CMD_ACCT_ADD_E1 "Erreur: Tu dois �tre admin pour cr�er des comptes MJ !"
#	define LANG_CMD_ACCT_ADD_E2 "Erreur: Compte [%s] d�j� existant dans la base de donn�es !"
#	define LANG_CMD_ACCT_ADD_OK "Fait. Compte [%s] avec password [%s] et niveau MJ [%d] ajout� a la base de donn�es."
#	define LANG_CMD_ACCT_BAN_E1 "Erreur: Ce personnage n'existe pas !"
#	define LANG_CMD_ACCT_BAN_OK "Fait. Le compte de %s est maintenant banni du serveur."

#	define LANG_CMD_NONE "Cette commande est inexistante."
#	define LANG_CMD_NOHELP "Il n'y a pas d'aide pour cette commande."
#	define LANG_CMD_UNK "Commande inconnue: %s"
#	define LANG_CMD_AVAIL "Commandes disponibles:"
#	define LANG_CMD_MHELP "Sous-commandes group�es par couleur et crochets. "\
		"Utiliser |cffccccff.help cmd|r, ou |cffccccff.help cmd sous-cmd|r pour lire une courte "\
		"description de la commande."
#	define LANG_CMD_ACLVL "Votre niveau d'acc�s est: %i"
#	define LANG_CMD_ONCOUNT "Nombre d'utilisateurs connect�s: %i"
#	define LANG_CMD_MOUNTLV "Tu dois �tre au minimum niveau 10 pour monter."
#	define LANG_CMD_MOUNTIN "Tu as une monture niveau %i de vitesse %i."
#	define LANG_CMD_PLRSAVE "Personnage sauvegard�."
#	define LANG_CMD_GMONL "Les MJs suivants sont actuellement connect�s:"
#	define LANG_CMD_GMOFFL "Il n'y a pas de MJs connect�s."
#	define LANG_CMD_BROADC "Serveur: %s"
#	define LANG_CMD_SUMMON "Tu invoques %s."
#	define LANG_CMD_BSUMMON "Tu es invoqu� par %s."
#	define LANG_CMD_TPTO "T�l�portation � la position de %s."

#	define LANG_CMD_NOPLR "Le joueur '%s' n'existe pas ou n'est pas connect�."
#	define LANG_CMD_NOTIMPL "Non impl�ment�."
#	define LANG_CMD_SSELEC "Tu dois s�lectionner un personnage ou une cr�ature."
#	define LANG_CMD_INCVAL "Valeurs incorrectes."
#	define LANG_CMD_NOCHAR "Aucun personnage n'est s�lectionn�."
#	define LANG_CMD_INCVAL_LV "Valeur incorrecte, le niveau doit �tre dans l'intervalle 1..255."
#	define LANG_CMD_NOSELNPC "Aucune s�lection, s�lectionne un PNJ d'abord."
#	define LANG_CMD_SHSELCR "Tu dois s�lectionner une cr�ature."
#	define LANG_CMD_NOSEL "Pas de s�lection."
#	define LANG_CMD_CF_VEN "La cr�ature s�lectionn�e doit avoir le marqueur PNJ VENDEUR."
#	define LANG_CMD_BADMAP "Erreur: Tu as essay� de te t�l�porter sur une map inexistante."
#	define LANG_CMD_GOBADGUID ".GOGUID %I64X - L'Unit�, le GameObj, le Joueur ou le Cadavre n'existe pas."
#	define LANG_CMD_KICK_ERR "Erreur: Le joueur que tu veux kick est inexistant ou n'est pas connect�"
#	define LANG_CMD_KICK_OK "Fait. %s a �t� kick� de ce serveur avec succ�s."

#	define LANG_CMD_VALSVD "Valeur sauvegard�e."
#	define LANG_CMD_ITEMADD "Item ajout�."
#	define LANG_CMD_ADDITEM "Item %i ajout� � %s."
#	define LANG_CMD_RVDITEM "%s � ajout� l'Item %i � ton inventaire."
#	define LANG_CMD_ADDQITEM "Items de la Qu�te %i ajout�s � %s."
#	define LANG_CMD_RVDQITEM "%s a transf�r� les items pour la Qu�te %i dans ton inventaire."
#	define LANG_CMD_ALLTPG "%s a maintenant acc�s � tous les chemins de taxi."
#	define LANG_CMD_ALLTPR "%s t'a ouvert tous les chemins de taxi."
#	define LANG_CMD_NOTPG "%s n'a maintenat plus acc�s � aucun des chemins de taxi."
#	define LANG_CMD_NOTPR "%s a supprim� tous vos chemins de taxi connus."
#	define LANG_CMD_GM_INVIS_ON "Tu es maintenant invisible."
#	define LANG_CMD_GM_INVIS_OFF "Tu es maintenant visible."
#	define LANG_CMD_GM_LEVEL_G "Tu as r�gl� le niveau de s�curit� de %s sur %i."
#	define LANG_CMD_GM_LEVEL_R "%s a r�gl� ton niveau de s�curit� sur %i."


/**************************
 ** OpCodes Used Strings **
 **************************/
#	define LANG_OPCODE_NPVPSERV "Le JcJ n'est pas autoris� sur les serveurs %s."

/*************************************
 ** World Strings + Console logging **
 *************************************/
#	define LANG_WORLD_NOBIND "CrFusion ne peut pas se verouiller sur ce port."
#	define LANG_WORLD_RSERV "Serveur de Liste des Royaumes demarre sur le port %d"
#	define LANG_WORLD_WSERV "Serveur de Monde demarre sur le port %d"
#	define LANG_WORLD_REALMR_PVP "JcJ"
#	define LANG_WORLD_REALMR_PVE "JdR"
#	define LANG_WORLD_REALMR_RPN "JdR Normal"
#	define LANG_WORLD_REALMR_RPP "JdR JcJ"
#	define LANG_WORLD_REALMR_NRM "Normal"
#	define LANG_WORLD_ENTERED "est entr� dans le monde."
#	define LANG_WORLD_SRVSTATS "|c8fff6420[Stats Serveur]|r\n|c8fff9920En ligne depuis: %d sec\nComptes: %d\nPersonnages: %d"

#endif