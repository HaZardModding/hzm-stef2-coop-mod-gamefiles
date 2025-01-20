// Gameplay File

OBJECT base_damage		Defines
{
    float value		1
}

OBJECT Mode1		WeaponModes
{
    float firetype		1
    float ammotype		1
    float startammo		1
    float ammorequired		1
    float bulletrange		1
    float regenamount		1
    float regentime		1
    float meansofdeath		1
    float power		1
    float splashdamage		1
    float bulletdamage		1
    float bulletspread		1
    float maxchargetime		1
    float clipsize		1
    float ammoinclip		1
    float firetime		1
    float spread		1
}

OBJECT Mode2		WeaponModes
{
    float ammorequired		1
    float ammotype		1
    float bulletrange		1
    float firetype		1
    float meansofdeath		1
    float power		1
    float regenamount		1
    float regentime		1
    float splashdamage		1
    float startammo		1
}

OBJECT Mode1MP		WeaponModes
{
}

OBJECT Mode2MP		WeaponModes
{
}

OBJECT Batleth		Weapons
{
    OBJECT Mode1		WeaponModes
    {
        float power		10
        float bulletdamage		25
        string ammorequired		N/A
        string ammotype		N/A
        string firetype		Melee
        string meansofdeath		sword
        string bulletrange		N/A
        string regenamount		N/A
        string regentime		N/A
        string splashdamage		N/A
        string startammo		N/A
        string bulletspread		N/A
        string ammoinclip		N/A
        string maxchargetime		N/A
        string clipsize		N/A
        string firetime		N/A
    }

    OBJECT Mode2		WeaponModes
    {
        float power		10
        float bulletdamage		50
        string ammorequired		N/A
        string ammotype		N/A
        string firetype		Melee
        string bulletrange		N/A
        string meansofdeath		sword
        string regenamount		N/A
        string regentime		N/A
        string splashdamage		N/A
        string startammo		N/A
        string bulletspread		N/A
        string ammoinclip		N/A
        string maxchargetime		N/A
        string clipsize		N/A
        string firetime		N/A
    }

    float bulletdamage		1
    float power		1
    string Description1		BatlethDesc1
    string Description2		BatlethDesc2
    string Description3		BatlethDesc3
    string InteractiveType		Usable
    string RadarDescription		BatlethRadar
}

OBJECT AssaultRifle		Weapons
{
    OBJECT Mode1		WeaponModes
    {
        float ammorequired		1
        string ammotype		Plasma
        float bulletdamage		15
        float bulletrange		2500
        string firetype		Bullet
        string meansofdeath		assult_rifle
        float power		25
        string regenamount		N/A
        string regentime		N/A
        string splashdamage		N/A
        float bulletspread		83
        float startammo		100
        string ammoinclip		N/A
        string maxchargetime		N/A
        string clipsize		N/A
        string firetime		N/A
    }

    OBJECT Mode2		WeaponModes
    {
        string firetype		Projectile
        string bulletspread		N/A
        float ammorequired		15
        string ammotype		Plasma
        string bulletdamage		N/A
        float startammo		0
        float power		25
        float ammoinclip		1
        float maxchargetime		2
        float firetime		0.5
        float bulletrange		1
        string meansofdeath		N/A
        float regenamount		1
        float regentime		1
        float splashdamage		1
        float clipsize		1
    }

    string Description1		AssaultRifleDesc1
    string Description2		AssaultRifleDesc2
    string Description3		AssaultRifleDesc3
    string InteractiveType		Usable
    string RadarDescription		AssaultRifleRadar
}

OBJECT CompressionRifle		Weapons
{
    OBJECT Mode1		WeaponModes
    {
        string meansofdeath		comp_rifle
        string ammoinclip		N/A
        float ammorequired		1
        string ammotype		Plasma
        float bulletdamage		20
        float bulletrange		2500
        float bulletspread		33
        string clipsize		N/A
        string firetime		N/A
        string firetype		Bullet
        string maxchargetime		N/A
        float power		21
        string regenamount		N/A
        string regentime		N/A
        string splashdamage		N/A
        float startammo		100
    }

    OBJECT Mode2		WeaponModes
    {
        string meansofdeath		vaporize
        string ammoinclip		N/A
        float ammorequired		15
        string ammotype		Plasma
        float bulletdamage		50
        float bulletrange		2500
        float bulletspread		33
        string clipsize		N/A
        string firetime		N/A
        string firetype		Bullet
        string maxchargetime		N/A
        float power		21
        string regenamount		N/A
        string regentime		N/A
        string splashdamage		N/A
        float startammo		0
    }

}

OBJECT IMOD		Weapons
{
    OBJECT Mode1		WeaponModes
    {
        string ammoinclip		N/A
        float ammorequired		5
        string ammotype		Plasma
        float bulletdamage		25
        float bulletrange		2500
        float bulletspread		0
        string clipsize		N/A
        string firetime		N/A
        string firetype		Bullet
        string maxchargetime		N/A
        string meansofdeath		imod
        float power		10
        string regenamount		N/A
        string regentime		N/A
        string splashdamage		N/A
        float startammo		100
    }

    OBJECT Mode2		WeaponModes
    {
        string meansofdeath		imod
        float startammo		0
        string splashdamage		N/A
        string regentime		N/A
        string regenamount		N/A
        float power		10
        string maxchargetime		N/A
        string firetype		Bullet
        string firetime		N/A
        string clipsize		N/A
        float bulletspread		0
        float bulletrange		2500
        float bulletdamage		50
        string ammotype		Plasma
        float ammorequired		15
        string ammoinclip		N/A
    }

    string Description1		IMODDesc1
    string Description2		IMODDesc2
    string Description3		IMODDesc3
    string InteractiveType		Usable
    string RadarDescription		IMODRadar
}

OBJECT GrenadeLauncher		Weapons
{
    OBJECT Mode1		WeaponModes
    {
        string ammoinclip		N/A
        float ammorequired		1
        string ammotype		Plasma
        string bulletdamage		N/A
        string bulletrange		N/A
        string bulletspread		N/A
        string clipsize		N/A
        float firetime		0.5
        string firetype		Projectile
        string maxchargetime		N/A
        string meansofdeath		N/A
        float startammo		70
        string splashdamage		N/A
        float power		50
        string regenamount		N/A
        string regentime		N/A
    }

    OBJECT Mode2		WeaponModes
    {
        string ammoinclip		N/A
        string ammotype		Plasma
        string bulletdamage		N/A
        string bulletrange		N/A
        string bulletspread		N/A
        string clipsize		N/A
        float firetime		0.5
        string firetype		Projectile
        string maxchargetime		N/A
        string meansofdeath		N/A
        float power		50
        string regenamount		N/A
        string regentime		N/A
        string splashdamage		N/A
        float startammo		0
        float ammorequired		1
    }

    OBJECT GrenadeLauncherMode1		Projectiles
    {
    }

    OBJECT GrenadeLauncherMode2		Projectiles
    {
    }

    string Description1		GrenadeLauncherDesc1
    string Description2		GrenadeLauncherDesc2
    string Description3		GrenadeLauncherDesc3
    string InteractiveType		Usable
    string RadarDescription		GrenadeLauncherRadar
}

OBJECT PhotonBurst		Weapons
{
    OBJECT Mode1		WeaponModes
    {
        string ammoinclip		N/A
        float ammorequired		1
        string ammotype		Plasma
        string bulletdamage		N/A
        string bulletrange		N/A
        string bulletspread		N/A
        string clipsize		N/A
        float firetime		0.5
        string firetype		Projectile
        string maxchargetime		N/A
        string meansofdeath		N/A
        float power		60
        string regenamount		N/A
        string regentime		N/A
        string splashdamage		N/A
        float startammo		70
    }

    OBJECT Mode2		WeaponModes
    {
        string firetype		Projectile
        string ammotype		Plasma
        float ammorequired		3
        float firetime		0.5
        string maxchargetime		N/A
        string clipsize		N/A
        string bulletspread		N/A
        string bulletrange		N/A
        string bulletdamage		N/A
        string ammoinclip		N/A
        float startammo		0
        string splashdamage		N/A
        string regentime		N/A
        string regenamount		N/A
        float power		60
        string meansofdeath		N/A
    }

    OBJECT PhotonBurstMode1		Projectiles
    {
    }

    OBJECT PhotonBurstMode2		Projectiles
    {
    }

    string Description1		PhotonBurstDesc1
    string Description2		PhotonBurstDesc2
    string Description3		PhotonBurstDesc3
    string InteractiveType		Usable
    string RadarDescription		PhotonBurstRadar
}

OBJECT TetryonGGun		Weapons
{
    OBJECT Mode1		WeaponModes
    {
        string ammotype		Plasma
        float ammorequired		1
        string ammoinclip		N/A
        float bulletdamage		10
        float bulletrange		2500
        float bulletspread		100
        string clipsize		N/A
        string firetime		N/A
        string firetype		Bullet
        string maxchargetime		N/A
        string meansofdeath		phaser
        float power		65
        string regenamount		N/A
        string regentime		N/A
        string splashdamage		N/A
        float startammo		80
    }

    OBJECT Mode2		WeaponModes
    {
        string firetype		Bullet
        string ammotype		Plasma
        float startammo		0
        float ammorequired		1
        float bulletrange		2500
        float bulletdamage		20
        string ammoinclip		N/A
        float bulletspread		50
        string clipsize		N/A
        string firetime		N/A
        string meansofdeath		phaser
        string maxchargetime		N/A
        float power		65
        string regenamount		N/A
        string regentime		N/A
        string splashdamage		N/A
    }

    string Description1		TetGunDesc1
    string Description2		TetGunDesc2
    string Description3		TetGunDesc3
    string InteractiveType		Usable
    string RadarDescription		TetGunRadar
}

OBJECT RomulanDisruptor		Weapons
{
    OBJECT Mode1		WeaponModes
    {
        string ammoinclip		N/A
        float ammorequired		1
        string ammotype		Plasma
        string bulletdamage		N/A
        string bulletrange		N/A
        string bulletspread		N/A
        string clipsize		N/A
        float firetime		0.33
        string firetype		Projectile
        string maxchargetime		N/A
        string meansofdeath		N/A
    }

}

OBJECT AttrexianRifle		Weapons
{
    OBJECT Mode1		WeaponModes
    {
        string firetype		Bullet
        string ammotype		Phaser
        float startammo		500
        float ammorequired		1
        float bulletrange		500
        float bulletdamage		1
        float regenamount		5
        float regentime		0.25
        string meansofdeath		vaporize
        float bulletspread		0
        float power		24
        string maxchargetime		N/A
        string firetime		N/A
        string clipsize		N/A
        string ammoinclip		N/A
        string splashdamage		N/A
    }

    OBJECT Mode2		WeaponModes
    {
        string ammoinclip		N/A
        float ammorequired		1
        string ammotype		Plasma
        string bulletdamage		N/A
        string bulletrange		N/A
        string bulletspread		N/A
        string clipsize		N/A
        float firetime		0.25
        string firetype		Projectile
        string maxchargetime		N/A
        string meansofdeath		N/A
        float power		60
        string regentime		N/A
        string splashdamage		N/A
        string regenamount		N/A
        float startammo		100
    }

    OBJECT AttrexianRifleMode2		Projectiles
    {
    }

    string Description1		AttrexianRifleDesc1
    string Description2		AttrexianRifleDesc2
    string Description3		AttrexianRifleDesc3
    string InteractiveType		Usable
    string RadarDescription		AttrexianRifleRadar
}

OBJECT RomulanRadiationGun		Weapons
{
    OBJECT Mode1		WeaponModes
    {
        string firetype		Projectile
        string ammotype		Plasma
        float startammo		100
        float ammorequired		1
        string ammoinclip		N/A
        float firetime		2
    }

    OBJECT Mode2		WeaponModes
    {
    }

    string Description1		RomRadGunDesc1
    string Description2		RomRadGunDesc2
    string Description3		RomRadGunDesc3
    string InteractiveType		Usable
    string RadarDescription		RomRadGunRadar
}

OBJECT GrenadeLauncherMode1		Projectiles
{
}

OBJECT GrenadeLauncherMode2		Projectiles
{
}

OBJECT PhotonBurstMode1		Projectiles
{
}

OBJECT PhotonBurstMode2		Projectiles
{
}

OBJECT AttrexianRifleMode2		Projectiles
{
}

OBJECT RomulanRadiationGunMode1		Projectiles
{
}

OBJECT Infinite		Defines
{
    float value		1e+006
}

OBJECT Ridiculous		Defines
{
    float value		10
}

OBJECT Super		Defines
{
    float value		5
}

OBJECT High		Defines
{
    float value		2
}

OBJECT Average		Defines
{
    float value		1
}

OBJECT Medium		Defines
{
    float value		0.66
}

OBJECT Low		Defines
{
    float value		0.33
}

OBJECT One		Defines
{
    float value		0.1
}

OBJECT Instant		Defines
{
    string value		Special
}

OBJECT InstantGib		Defines
{
    string value		Special
}

OBJECT base_health		Defines
{
    float value		1
}

OBJECT BorgBoss		Enemy
{
    float health		1000
    float damage		1
    string Description1		BorgBossDesc1
    string InteractiveType		Enemy
    string Description2		BorgBossDesc2
    string Description3		BorgBossDesc3
    string RadarDescription		BorgBossRadar
}

OBJECT Type2Cruiser		Enemy
{
}

OBJECT RomulanHoloSoldiers		Enemy
{
}

OBJECT Type2CruiserTurret		Enemy
{
}

OBJECT Type3Quadraped		Enemy
{
}

OBJECT Type4Predator		Enemy
{
}

OBJECT Type5Commander		Enemy
{
}

OBJECT IdryllSoldiers		Enemy
{
}

OBJECT KlingonMercs		Enemy
{
}

OBJECT KlingonBoss		Enemy
{
}

OBJECT RenegadeRomulanSoldiers		Enemy
{
}

OBJECT RomulanInformantBoss		Enemy
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    string Description2		RomulanInformantBossDesc2
    string Description3		RomulanInformantBossDesc3
    string InteractiveType		Enemy
    float PainChance		1
    string RadarDescription		RomulanInformantRadar
    float health		300
}

OBJECT MommaBug		Enemy
{
}

OBJECT Lurker_PackageLoneLurker		BehaviorPackageData
{
    float Chance_ChargeOnFirstAttack		0.5
    float Range_MeleeCombat		128
    float Range_Retreat		192
    float Range_MinChargeDistance		100
    float Range_Spar		256
    float Chance_Attack		0.35
    float Chance_AttackWhileInSparringRange		0.55
    float Chance_ApproachRunning		0.25
    float Chance_StrafeAfterBeingAttacked		0.8
    float Chance_StrafeWhileInConeOfFire		0.45
    float Chance_SidestepWhileInConeOfFire		0.75
    float Chance_DoSprayAttack		0.35
    float Chance_StrafeAfterPain		0.25
}

OBJECT BACK_PEDAL		StateData
{
}

OBJECT Chewer_PackageLoneChewer		BehaviorPackageData
{
    float Chance_ApproachRunning		0.25
    float Chance_Attack		0.35
    float Chance_AttackWhileInSparringRange		0.55
    float Chance_SidestepWhileInConeOfFire		0.75
    float Chance_StrafeAfterBeingAttacked		0.8
    float Chance_StrafeAfterPain		0.25
    float Chance_StrafeWhileInConeOfFire		0.45
    float Range_MeleeCombat		128
    float Range_Retreat		192
    float Range_Spar		256
    float Chance_ChargeOnFirstAttack		0.25
    float Chance_DoSprayAttack		0.6
    float Range_MinChargeDistance		100
}

OBJECT Lurker_PackageGroupLurker		BehaviorPackageData
{
    float Chance_ApproachRunning		0.25
    float Chance_Attack		0.35
    float Chance_AttackWhileInSparringRange		0.55
    float Chance_ChargeOnFirstAttack		0.25
    float Chance_DoSprayAttack		0.5
    float Chance_SidestepWhileInConeOfFire		0.75
    float Chance_StrafeAfterBeingAttacked		0.8
    float Chance_StrafeAfterPain		0.25
    float Chance_StrafeWhileInConeOfFire		0.45
    float Range_MeleeCombat		128
    float Range_MinChargeDistance		100
    float Range_Retreat		192
    float Range_Spar		256
}

OBJECT Chewer_PackageGroupChewer		BehaviorPackageData
{
    float Chance_ApproachRunning		0.25
    float Chance_Attack		0.8
    float Chance_AttackWhileInSparringRange		0.55
    float Chance_ChargeOnFirstAttack		0.25
    float Chance_DoSprayAttack		0.6
    float Chance_SidestepWhileInConeOfFire		0.75
    float Chance_StrafeAfterBeingAttacked		0.8
    float Chance_StrafeAfterPain		0.25
    float Chance_StrafeWhileInConeOfFire		0.45
    float Range_MeleeCombat		128
    float Range_MinChargeDistance		100
    float Range_Retreat		256
    float Range_Spar		512
}

OBJECT Basher_PackageLoneBasher		BehaviorPackageData
{
    float Chance_ApproachRunning		0.25
    float Chance_Attack		0.5
    float Chance_AttackWhileInSparringRange		0.55
    float Chance_ChargeOnFirstAttack		0.6
    float Chance_DoSprayAttack		0.6
    float Chance_SidestepWhileInConeOfFire		0.75
    float Chance_StrafeAfterBeingAttacked		0.8
    float Chance_StrafeAfterPain		0.25
    float Chance_StrafeWhileInConeOfFire		0.45
    float Range_MeleeCombat		128
    float Range_MinChargeDistance		100
    float Range_Retreat		192
    float Range_Spar		256
    float Range_SprayAttack		128
}

OBJECT HoldPhaser		Animations
{
    string Draw		phaser_draw
    string Idle		phaser_idle
    string Fire		phaser_fire
    string PutAway		phaser_putaway
    string PreFire		phaser_prefire
    string PostFire		phaser_postfire
    string Aim		phaser_aim
    string Melee		phaser_melee
    string CombatWalk		swat_walk
    string CombatRun		swat_run
    string CombatBackpedal		swat_backpedal
    string CombatLStrafe		swat_lstrafe
    string CombatRStrafe		swat_rstrafe
    string IdleWalk		walk
    string IdleRun		run
    string IdleBackpedal		backpedal
    string IdleLStrafe		strafe_left
    string IdleRStrafe		strafe_right
    string CombatLegIdle		swat_calm_idle
    string IdleLegIdle		idle
    string CombatGunIdle		phaser_tense_idle
    string IdleGunIdle		phaser_calm_idle
    float AimTimeMin		0.25
    float AimTimeMax		0.3
    float FireTimeMin		1
    float FireTimeMax		1.25
    float MaxTorsoYaw		80
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float spreadx		600
    float spready		600
}

OBJECT HoldCompRifle		Animations
{
    string Draw		compressionrifle_draw
    string Fire		compressionrifle_fire
    string Idle		compressionrifle_idle
    string PutAway		compressionrifle_putaway
    string PostFire		compressionrifle_postfire
    string PreFire		compressionrifle_prefire
    string Melee		compressionrifle_melee
    string Aim		compressionrifle_aim
    string CombatBackpedal		swat_backpedal
    string CombatGunIdle		compressionrifle_tense_idle
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		swat_calm_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string IdleBackpedal		backpedal
    string IdleGunIdle		compressionrifle_idle
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    float AimTimeMax		0.3
    float AimTimeMin		0.25
    float FireTimeMax		1.25
    float FireTimeMin		1
    float spreadx		10
    float spready		10
    string CombatGunTwitch		weapon-twitch
    string IdleGunTwitch		weapon-twitch
    float ShotCount		3
}

OBJECT HoldAssaultRifle		Animations
{
    string Draw		fieldassaultrifle_draw
    string Fire		fieldassaultrifle_fire
    string Idle		fieldassaultrifle_idle
    string PostFire		fieldassaultrifle_postfire
    string PreFire		fieldassaultrifle_prefire
    string PutAway		fieldassaultrifle_putaway
    string Melee		fieldassaultrifle_melee
    string Aim		fieldassaultrifle_aim
    string CombatGunIdle		fieldassaultrifle_tense_idle
    string IdleGunIdle		fieldassaultrifle_calm_idle
    string CombatBackpedal		swat_backpedal
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		swat_calm_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string IdleBackpedal		backpedal
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    float AimTimeMax		0.3
    float AimTimeMin		0.25
    float FireTimeMax		1.25
    float FireTimeMin		1
    float spreadx		100
    float spready		100
}

OBJECT HoldIMod		Animations
{
    string Draw		i-mod_draw
    string Fire		i-mod_fire
    string Idle		i-mod_idle
    string PostFire		i-mod_postfir
    string PreFire		i-mod_prefire
    string PutAway		i-mod_putaway
    string Aim		i-mod_aim
    string Melee		i-mod_melee
    string CombatGunIdle		i-mod_tense_idle
    string IdleGunIdle		i-mod_calm_idle
    string CombatBackpedal		swat_backpedal
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		swat_calm_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string IdleBackpedal		backpedal
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    float AimTimeMax		0.3
    float AimTimeMin		0.2
    float FireTimeMax		1.25
    float FireTimeMin		1
    float spreadx		10
    float spready		10
    float ShotCount		3
}

OBJECT AnimSet1		Animations
{
    string Idle		idle
    string IdleToWalk		idle
    string Run		idle
    string Walk		idle
    string WalkToIdle		idle
}

OBJECT AnimSet2		Animations
{
    string Idle		idle
    string IdleToWalk		idle
    string Run		idle
    string Walk		idle
    string WalkToIdle		idle
}

OBJECT HoldIdryllGauntletWithShield		Animations
{
    string Draw		gauntlet_shield_draw
    string Fire		gauntlet_shield_fire
    string Idle		gauntlet_shield_idle
    string PostFire		gauntlet_shield_postfire
    string PreFire		gauntlet_shield_prefire
    string PutAway		gauntlet_shield_putaway
    string Aim		gauntlet_shield_idle
    string CombatGunIdle		idle
    string IdleGunIdle		idle
    string CombatBackpedal		swat_backpedal
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		swat_calm_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string IdleBackpedal		backpedal
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    float AimTimeMax		-1
    float AimTimeMin		-1
    float FireTimeMax		-1
    float FireTimeMin		-1
    float spreadx		75
    float spready		75
    string Melee		MeleeCombo
}

OBJECT GOTO_COMBAT_NODE		StateData
{
    string MovementMode		RUN
}

OBJECT HoldIdryllGauntletNoShield		Animations
{
    string Draw		gauntlet_noshield_draw
    string Fire		gauntlet_noshield_fire
    string Idle		gauntlet_noshield_idle
    string PostFire		gauntlet_noshield_postfire
    string PreFire		gauntlet_noshield_prefire
    string PutAway		gauntlet_noshield_putaway
    string Aim		gauntlet_noshield_idle
    string CombatGunIdle		idle
    string IdleGunIdle		idle
    string CombatBackpedal		swat_backpedal
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		swat_calm_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string IdleBackpedal		backpedal
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    float AimTimeMax		-1
    float AimTimeMin		-1
    float FireTimeMax		-1
    float FireTimeMin		-1
    float spreadx		75
    float spready		75
    string Melee		melee_noshield-combo
}

OBJECT HoldIdryllMortar		Animations
{
    string Draw		gauntlet_mortar_draw
    string Fire		gauntlet_mortar_fire
    string Idle		gauntlet_mortar_idle
    string PostFire		gauntlet_mortar_postfire
    string PreFire		gauntlet_mortar_prefire
    string PutAway		gauntlet_mortar_putaway
    string CombatGunIdle		idle
    string IdleGunIdle		idle
    string CombatBackpedal		swat_backpedal
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		swat_calm_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string IdleBackpedal		backpedal
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    float AimTimeMax		-1
    float AimTimeMin		-1
    float FireTimeMax		-1
    float FireTimeMin		-1
    float spreadx		600
    float spready		600
    string Aim		gauntlet_mortar_aim
}

OBJECT Merc		Enemy
{
    OBJECT HoldKlingonDisruptorRifle		Animations
    {
    }

}

OBJECT Enemy		InteractiveTypes
{
    float Blue		0
    float Green		0
    float Red		1
    float ShowInRadar		1
    float AlwaysShowReticle		0
    float ShowInSimpleMode		1
}

OBJECT Friendly		InteractiveTypes
{
    float Blue		0.5
    float Red		0.5
    float ShowInRadar		1
    float Green		0.38
    float AlwaysShowReticle		0
    float ShowInSimpleMode		0
}

OBJECT Teammate		InteractiveTypes
{
    float Blue		0
    float Green		1
    float Red		0
    float ShowInRadar		1
    float AlwaysShowReticle		0
    float ShowInSimpleMode		0
}

OBJECT Usable		InteractiveTypes
{
    float Blue		0.5
    float Green		1
    float Red		1
    float ShowInRadar		1
    float AlwaysShowReticle		1
    float ShowInSimpleMode		0
}

OBJECT TricorderUsable		InteractiveTypes
{
    float Blue		1
    float Green		1
    float Red		0
    float ShowInRadar		1
    float ShowInSimpleMode		0
}

OBJECT Destructable		InteractiveTypes
{
    float Blue		0.25
    float Green		0.5
    float Red		1
    float ShowInRadar		1
    float ShowInSimpleMode		0
}

OBJECT Location		InteractiveTypes
{
    float ShowInRadar		1
    float Green		0
    float Red		0
    float Blue		1
    float ShowInSimpleMode		0
}

OBJECT MissionObjective		InteractiveTypes
{
    float Green		1
    float Blue		1
    float BlipShader		1
    float SelectedBlipShader		1
    float RadarDescription		1
    float Red		1
    float ShowInRadar		1
    float ShowInSimpleMode		0
}

OBJECT TransportOutFederation		DisplayEffects
{
    string ShaderName		transport
    string SoundName		snd_bodytransportout
    string EffectName		fx/fx-beamsparkle.tik
    string AnimName		transport_out
    string EffectPosName		centroid
    float EffectTime		1.25
    float TransportTime		1.25
    float Immobilize		1
    float AttachEffect		0
    float HideFeatures		1
}

OBJECT TransportInFederation		DisplayEffects
{
    string AnimName		transport_in
    string EffectName		fx/fx-beamsparkle.tik
    string EffectPosName		centroid
    float EffectTime		1.25
    float TransportTime		1.25
    string ShaderName		transport
    string SoundName		snd_bodytransportin
    float Immobilize		1
    float AttachEffect		0
    float HideFeatures		1
}

OBJECT TransportOutBorg		DisplayEffects
{
    string AnimName		transport_out
    string EffectName		fx/fx-beamsparkle-borg-out.tik
    string EffectPosName		Bip01
    string SoundName		snd_bodytransportout
    string ShaderName		transport-borg
    float EffectTime		0.25
    float TransportTime		0.75
    float Immobilize		1
    float AttachEffect		0
    float HideFeatures		1
}

OBJECT TransportInBorg		DisplayEffects
{
    string AnimName		transport_in
    string EffectName		fx/fx-beamsparkle-borg-in.tik
    string EffectPosName		centroid
    string SoundName		snd_bodytransportin
    string ShaderName		transport-borg
    float EffectTime		0.75
    float TransportTime		0.75
    float Immobilize		1
    float AttachEffect		0
    float HideFeatures		1
}

OBJECT TransportOutIdryll		DisplayEffects
{
    string AnimName		transport_out
    string EffectName		fx/fx-beamsparkle-drull.tik
    string EffectPosName		centroid
    float EffectTime		0.75
    string ShaderName		transport-idryll
    string SoundName		snd_bodytransportout
    float TransportTime		0.75
    float Immobilize		1
    float AttachEffect		0
    float HideFeatures		1
}

OBJECT TransportInIdryll		DisplayEffects
{
    string AnimName		transport_in
    string EffectName		fx/fx-beamsparkle-drull.tik
    string EffectPosName		centroid
    float EffectTime		0.75
    string ShaderName		transport-idryll
    string SoundName		snd_bodytransportin
    float TransportTime		0.75
    float Immobilize		1
    float AttachEffect		0
    float HideFeatures		1
}

OBJECT NonInteractive		InteractiveTypes
{
    float Red		0.85
    float Blue		0.6
    float Green		0.42
    float ShowInRadar		0
    float ShowInSimpleMode		0
}

OBJECT Alcove		BorgEnvironment
{
    string InteractiveType		NonInteractive
    float Description1		1
    string Description2		BorgAlcoveDesc2
    string Description3		BorgAlcoveDesc3
}

OBJECT HealthTerminal		BorgEnvironment
{
    string InteractiveType		Usable
    string RadarDescription		BorgHealthTerminalRadar
    string Description2		BorgHealthTerminalDesc2
    string Description1		BorgHealthTerminalDesc1
    string Description3		BorgHealthTerminalDesc3
}

OBJECT EnergyTerminal		BorgEnvironment
{
    string InteractiveType		Usable
    string RadarDescription		BorgEnergyTerminalRadar
    string Description1		BorgEnergyTerminalDesc1
    string Description2		BorgEnergyTerminalDesc2
    string Description3		BorgEnergyTerminalDesc3
}

OBJECT PlasmaConduit		BorgEnvironment
{
    string InteractiveType		Destructable
    string RadarDescription		BorgPlasmaConduitRadar
    string Description1		BorgPlasmaConduitDesc1
    string Description2		BorgPlasmaConduitDesc2
    string Description3		BorgPlasmaConduitDesc3
}

OBJECT PlasmaConduitDamaged		BorgEnvironment
{
    string InteractiveType		NonInteractive
    string Description1		BorgPlasmaConduitDamagedDesc1
    string Description2		BorgPlasmaConduitDamagedDesc2
    string Description3		BorgPlasmaConduitDamagedDesc3
}

OBJECT PowerCupling		BorgEnvironment
{
    string InteractiveType		Destructable
    string RadarDescription		BorgPowerCouplingRadar
    string Description1		BorgPowerCouplingDesc1
    string Description2		BorgPowerCouplingDesc2
    string Description3		BorgPowerCouplingDesc3
}

OBJECT PowerCuplingDamaged		BorgEnvironment
{
    string InteractiveType		NonInteractive
    string Description1		BorgPowerCouplingDamagedDesc1
    string Description2		BorgPowerCouplingDamagedDesc2
    string Description3		BorgPowerCouplingDamagedDesc3
}

OBJECT ShieldPanel		BorgEnvironment
{
    string InteractiveType		TricorderUsable
    string RadarDescription		BorgShieldPanelRadar
    string Description1		BorgShieldPanelDesc1
    string Description2		BorgShieldPanelDesc2
    string Description3		BorgShieldPanelDesc3
}

OBJECT DistributionNode		BorgEnvironment
{
    string InteractiveType		Destructable
    string RadarDescription		BorgDistributionNodeRadar
    string Description1		BorgDistributionNodeDesc1
    string Description2		BorgDistributionNodeDesc2
    string Description3		BorgDistributionNodeDesc3
}

OBJECT DistributionNodeDamaged		BorgEnvironment
{
    string InteractiveType		NonInteractive
    string Description1		BorgDistributionNodeDamagedDesc1
    string Description2		BorgDistributionNodeDamagedDesc2
    string Description3		BorgDistributionNodeDamagedDesc3
}

OBJECT Panel		BorgEnvironment
{
    string Description1		BorgPanelDesc1
    string Description2		BorgPanelDesc2
    string Description3		BorgPanelDesc3
    string InteractiveType		TricorderUsable
    string RadarDescription		PanelRadar
}

OBJECT FadeOutPhaser		DisplayEffects
{
    string ShaderName		phaser_death
    float EffectTime		1.5
    string SoundName		snd_phaserdeath
    string EffectName		fx/fx-fadeout-phaser.tik
    float FadeTime		2
    string EffectPosName		randombone
    float NumEffects		10
    float Immobilize		1
    float AnimName		1
    float AttachEffect		1
    float HideFeatures		0
}

OBJECT FadeOutDisruptor		DisplayEffects
{
    string EffectName		fx/fx-fadeout-disruptor.tik
    string EffectPosName		randombone
    float EffectTime		1.5
    float FadeTime		2
    string ShaderName		disruptor_death
    string SoundName		snd_phaserdeath
    float NumEffects		12
    float Immobilize		1
    float AttachEffect		1
    float HideFeatures		0
}

OBJECT HoldIdryllGauntletMelee		Animations
{
    string Draw		gauntlet_melee_draw
    string Fire		gauntlet_melee_fire
    string Idle		gauntlet_melee_idle
    string PostFire		gauntlet_melee_postfire
    string PreFire		gauntlet_melee_prefire
    string PutAway		gauntlet_melee_putaway
    string Melee		MeleeCombo
    string CombatGunIdle		idle
    string IdleGunIdle		idle
    string CombatBackpedal		swat_backpedal
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		swat_calm_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string IdleBackpedal		backpedal
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    float AimTimeMax		-1
    float AimTimeMin		-1
    float FireTimeMax		-1
    float FireTimeMin		-1
    float spreadx		75
    float spready		75
}

OBJECT TeammateData		TeammateRoster
{
    string HealthyAnimation		idle
    string HealthyShader		hud_mission_objective_monitor_healthy
    string InjuredAnimation		idle
    string InjuredShader		hud_mission_objective_monitor_injured
    string CriticalAnimation		idle
    string CriticalShader		hud_mission_objective_monitor_critical
    string DefaultShader		EMPTY
}

OBJECT Teammate1		TeammateRoster
{
    string StatusShader		EMPTY
    string Archetype		EMPTY
    float Archetype		1
}

OBJECT Teammate2		TeammateRoster
{
    string Archetype		EMPTY
    string StatusShader		EMPTY
}

OBJECT Teammate3		TeammateRoster
{
    string StatusShader		EMPTY
    string Archetype		EMPTY
}

OBJECT Teammate4		TeammateRoster
{
    string StatusShader		EMPTY
    string Archetype		EMPTY
}

OBJECT RadarDialog		UI
{
    float RadarString		1
}

OBJECT LoadSaveGame		UI
{
    string ScreenShotShader		EMPTY
    float EnableLoadSaveButton		0
    float EnableDeleteButton		0
    string SaveGameList		EMPTY
    float IsSaveList		0
    string SaveGameName		EMPTY
}

OBJECT ModelRendering		Rendering
{
    string animation		idle
    float offset_x		1
    float offset_y		1
    float offset_z		1
    float fov_h		90
    float fov_v		60
    float angles_yaw		1
    float angles_pitch		1
    float angles_roll		1
}

OBJECT Leviathan_PackageLeviathan		BehaviorPackageData
{
    float Chance_ApproachRunning		0.25
    float Chance_Attack		0.35
    float Chance_AttackWhileInSparringRange		0.55
    float Chance_ChargeOnFirstAttack		0.25
    float Chance_SidestepWhileInConeOfFire		0.75
    float Chance_StrafeAfterBeingAttacked		0.8
    float Chance_StrafeAfterPain		0.25
    float Chance_StrafeWhileInConeOfFire		0.45
    float Range_MeleeCombat		128
    float Range_MinChargeDistance		100
    float Range_Retreat		192
    float Range_Spar		256
    float Chance_DoSprayAttack		1
}

OBJECT Lurker		Aliens
{
    OBJECT PainChance		DamageType
    {
    }

    float fov		360
    float health		60
    float playerhatemodifier		1.5
    float visiondistance		1200
    float Description1		1
    string Description2		LurkerDesc2
    string Description3		LurkerDesc3
    string InteractiveType		Enemy
    string RadarDescription		LurkerRadar
    float PainChance		1
}

OBJECT Chewer		Aliens
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    string Description2		ChewerDesc2
    string Description3		ChewerDesc3
    string InteractiveType		Enemy
    string RadarDescription		ChewerRadar
    float fov		360
    float health		220
    float playerhatemodifier		1.5
    float visiondistance		1200
    float PainChance		1
    float plasmashotgun		1
    float phaser		1
    float electric		1
}

OBJECT Basher		Aliens
{
    OBJECT PainChance		DamageType
    {
    }

    string InteractiveType		Enemy
    string RadarDescription		BasherRadar
    float fov		360
    float health		500
    float playerhatemodifier		1.5
    float visiondistance		1200
    float Description1		1
    string Description2		BasherDesc2
    string Description3		BasherDesc3
    float PainChance		1
    float electric		1
    float explosion		1
    float phaser		1
    float plasmashotgun		1
    float small_explosion		1
}

OBJECT Quadraped		Aliens
{
    OBJECT PainChance		DamageType
    {
        float comp_rifle		0.4
        float disruptor		0.4
        float electric		0.15
    }

    float Description1		1
    string Description2		QuadrapedDesc2
    string Description3		QuadrapedDesc3
    string InteractiveType		Enemy
    string RadarDescription		QuadRadar
    float fov		360
    float health		1625
    float playerhatemodifier		1.5
    float visiondistance		1200
    float PainChance		1
}

OBJECT Predator		Aliens
{
    OBJECT PainChance		DamageType
    {
    }

    string InteractiveType		Enemy
    float Description1		1
    string Description2		StalkerDesc2
    string Description3		StalkerDesc3
    string RadarDescription		StalkerRadar
    float fov		360
    float health		1800
    float playerhatemodifier		1.5
    float visiondistance		1200
    float PainChance		1
}

OBJECT Commander		Aliens
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    string Description2		CommanderDesc2
    string Description3		CommanderDesc3
    string InteractiveType		Enemy
    string RadarDescription		CommRadar
    float fov		360
    float health		2500
    float playerhatemodifier		1.5
    float visiondistance		1200
    float PainChance		1
}

OBJECT AndorianFemale		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    string Description2		AndorianFemaleDesc2
    string Description3		AndorianFemaleDesc3
    string InteractiveType		Enemy
    float RadarDescription		1
    float fov		360
    float health		30
    float playerhatemodifier		1.5
    float visiondistance		2400
    float PainChance		1
}

OBJECT AndorianMale		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    string Description2		AndorianMaleDesc2
    string Description3		AndorianMaleDesc3
    string InteractiveType		Enemy
    float RadarDescription		1
    float fov		360
    float health		30
    float playerhatemodifier		1.5
    float visiondistance		2400
    float PainChance		1
}

OBJECT AttrexianFemale		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    string Description2		AttrexianFemaleDesc2
    string Description3		AttrexianFemaleDesc3
    string InteractiveType		Friendly
    string RadarDescription		AttrexianFemaleRadar
    float fov		360
    float health		100
    float playerhatemodifier		1.5
    float visiondistance		1200
    float PainChance		1
}

OBJECT AttrexianMale		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    string Description2		AttrexianMaleDesc2
    string Description3		AttrexianMaleDesc3
    string InteractiveType		Friendly
    string RadarDescription		AttrexianMaleRadar
    float fov		360
    float health		100
    float playerhatemodifier		1.5
    float visiondistance		1200
    float PainChance		1
}

OBJECT BorgDroneFemale		Borg
{
    string Description1		BorgDroneFemaleDesc1
    float visiondistance		1200
    float playerhatemodifier		1.5
    float health		80
    float fov		360
    string RadarDescription		BorgDroneFemaleRadar
    string InteractiveType		Enemy
    string Description3		BorgDroneFemaleDesc3
    string Description2		BorgDroneFemaleDesc2
    float PainChance		1
}

OBJECT BorgDroneMale		Borg
{
    string InteractiveType		Enemy
    float fov		360
    float health		80
    float playerhatemodifier		1.5
    float visiondistance		1200
    string RadarDescription		BorgDroneMaleRadar
    string Description3		BorgDroneMaleDesc3
    string Description2		BorgDroneMaleDesc2
    string Description1		BorgDroneMaleDesc1
    float PainChance		1
}

OBJECT CruiserTurret		Aliens
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    string Description2		CruiserTurretDesc2
    string Description3		CruiserTurretDesc3
    string InteractiveType		Enemy
    string RadarDescription		CruisRadar
    float fov		360
    float health		120
    float playerhatemodifier		1.5
    float visiondistance		5000
    float PainChance		1
}

OBJECT BugFemale		Bugs
{
    OBJECT PainChance		DamageType
    {
        float comp_rifle		1
        float disruptor		1
        float electric		1
        float imod_primary		1
        float vaporize_comp		1
        float vaporize_disruptor		1
    }

    string Description1		BugFemaleDesc1
    string Description2		BugFemaleDesc2
    string Description3		BugFemaleDesc3
    string InteractiveType		Enemy
    string RadarDescription		BugFemaleRadar
    float fov		360
    float health		200
    float playerhatemodifier		1.5
    float visiondistance		1200
    float PainChance		1
}

OBJECT BugFemaleNoSack		Bugs
{
    float Description1		1
    float Description2		1
    float Description3		1
    string InteractiveType		Enemy
    float RadarDescription		1
    float fov		360
    float health		25
    float playerhatemodifier		1.5
    float visiondistance		1200
    float PainChance		1
}

OBJECT BugMale		Bugs
{
    OBJECT PainChance		DamageType
    {
        float comp_rifle		1
        float disruptor		1
        float electric		1
        float imod_primary		1
        float vaporize_comp		1
        float vaporize_disruptor		1
    }

    string Description1		BugMaleDesc1
    string Description2		BugMaleDesc2
    string Description3		BugMaleDesc3
    string InteractiveType		Enemy
    string RadarDescription		BugMaleRadar
    float fov		360
    float health		140
    float playerhatemodifier		1.5
    float visiondistance		1200
    float PainChance		1
}

OBJECT BugQueen		Bugs
{
    OBJECT PainChance		DamageType
    {
        float comp_rifle		1
        float disruptor		1
        float electric		1
        float imod_primary		1
        float vaporize_comp		1
        float vaporize_disruptor		1
    }

    string Description1		BugQueenDesc1
    string Description2		BugQueenDesc2
    string Description3		BugQueenDesc3
    string InteractiveType		Enemy
    string RadarDescription		QueenRadar
    float fov		360
    float health		2000
    float playerhatemodifier		1.5
    float visiondistance		3000
    float PainChance		1
}

OBJECT BugSack		Bugs
{
    float Description1		1
    float Description2		1
    float Description3		1
    string InteractiveType		Enemy
    float RadarDescription		1
    float fov		360
    float health		20
    float playerhatemodifier		1.5
    float visiondistance		1200
    float PainChance		1
}

OBJECT BugSmall		Bugs
{
    string Description1		BugSmallDesc1
    string Description2		BugSmallDesc2
    string Description3		BugSmallDesc3
    string InteractiveType		Enemy
    string RadarDescription		BugSmallRadar
    float fov		360
    float health		5
    float playerhatemodifier		1.5
    float visiondistance		1200
    float PainChance		1
}

OBJECT BugSmallExplosive		Bugs
{
    string Description1		BugSmallExplosiveDesc1
    string Description2		BugSmallExplosiveDesc2
    string Description3		BugSmallExplosiveDesc3
    string InteractiveType		Enemy
    string RadarDescription		BugSmallExplosiveRadar
    float fov		360
    float health		5
    float playerhatemodifier		1.5
    float visiondistance		1200
    float PainChance		1
}

OBJECT DrullFemale		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    string Description2		DrullFemaleDesc2
    string Description3		DrullFemaleDesc3
    string InteractiveType		Friendly
    string RadarDescription		DrullFemaleRadar
    float fov		360
    float health		100
    float playerhatemodifier		1.5
    float visiondistance		1200
    float PainChance		1
}

OBJECT DrullMale		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    string Description2		DrullMaleDesc2
    string Description3		DrullMaleDesc3
    string InteractiveType		Friendly
    string RadarDescription		DrullMaleRadar
    float fov		360
    float health		100
    float playerhatemodifier		1.5
    float visiondistance		1200
    float PainChance		1
}

OBJECT Oolpax		NPC
{
    string Description1		OmagDesc1
    string Description2		OmagDesc2
    string Description3		OmagDesc3
    string InteractiveType		Enemy
    string RadarDescription		OmagRadar
    float fov		360
    float health		100
    float playerhatemodifier		1.5
    float visiondistance		1200
    float PainChance		1
}

OBJECT HazardTeamBaseFemale		HazardTeam
{
    float Description1		1
    float Description2		1
    float Description3		1
    string InteractiveType		Teammate
    float RadarDescription		1
    float fov		360
    float health		1000
    float visiondistance		1200
    float playerhatemodifier		0
    float PainChance		1
}

OBJECT HazardTeamBaseMale		HazardTeam
{
    float Description1		1
    float Description2		1
    float Description3		1
    string InteractiveType		Teammate
    float RadarDescription		1
    float fov		360
    float health		1000
    float playerhatemodifier		0
    float visiondistance		1200
    float PainChance		1
}

OBJECT HazardTeamChang		HazardTeam
{
    OBJECT ModelRendering		Rendering
    {
        float angles_yaw		180
        float offset_x		28
        float offset_y		0
        float offset_z		-87
        float fov_h		30
        float fov_v		30
    }

    string Description1		ChangDesc1
    string Description2		ChangDesc2
    string Description3		ChangDesc3
    string InteractiveType		Teammate
    string RadarDescription		ChangRadar
    float fov		360
    float health		1000
    float playerhatemodifier		0
    float visiondistance		1200
    string Model		char/hazardteam_chang.tik
    float PainChance		1
}

OBJECT HazardTeamChell		HazardTeam
{
    OBJECT ModelRendering		Rendering
    {
        float offset_z		-87
        float offset_y		0
        float offset_x		28
        float angles_yaw		180
        float Description1		1
        float angles_pitch		0
        float angles_roll		0
        float fov_h		30
        float fov_v		30
    }

    string Description1		ChellDesc1
    string Description2		ChellDesc2
    string Description3		ChellDesc3
    string InteractiveType		Teammate
    string RadarDescription		ChellRadar
    float fov		360
    float health		1000
    float playerhatemodifier		0
    float visiondistance		1200
    string Model		char/hazardteam_chell.tik
    float PainChance		1
}

OBJECT HazardTeamFranklin		HazardTeam
{
    OBJECT ModelRendering		Rendering
    {
        float angles_pitch		0
        float angles_roll		0
        float angles_yaw		180
        float offset_x		28
        float offset_y		0
        float offset_z		-87
        float fov_h		30
        float fov_v		30
    }

    string Description1		FranklinDesc1
    string Description2		FranklinDesc2
    string Description3		FranklinDesc3
    string InteractiveType		Teammate
    string RadarDescription		FranklinRadar
    float fov		360
    float health		1000
    float playerhatemodifier		0
    float visiondistance		1200
    string Model		char/hazardteam_franklin.tik
    float PainChance		1
}

OBJECT HazardTeamGonzales		HazardTeam
{
    OBJECT ModelRendering		Rendering
    {
        float angles_pitch		0
        float angles_roll		0
        float angles_yaw		180
        float offset_x		28
        float offset_y		0
        float offset_z		-87
        float fov_h		30
        float fov_v		30
    }

    string Description1		GonzalesDesc1
    string Description2		GonzalesDesc2
    string Description3		GonzalesDesc3
    string InteractiveType		Teammate
    string RadarDescription		GonzalesRadar
    float fov		360
    float health		1000
    float playerhatemodifier		0
    float visiondistance		1200
    string Model		char/hazardteam_gonzales.tik
    float PainChance		1
}

OBJECT HazardTeamJurot		HazardTeam
{
    OBJECT ModelRendering		Rendering
    {
        float fov_h		30
        float fov_v		30
    }

    string Description1		JurotDesc1
    string Description2		JurotDesc2
    string Description3		JurotDesc3
    string InteractiveType		Teammate
    string RadarDescription		JurotRadar
    float fov		360
    float health		1000
    float playerhatemodifier		0
    float visiondistance		1200
    string Model		char/hazardteam_jurot.tik
    float PainChance		1
}

OBJECT HazardTeamKourban		HazardTeam
{
    OBJECT ModelRendering		Rendering
    {
        float angles_pitch		0
        float angles_roll		0
        float angles_yaw		180
        float offset_x		28
        float offset_y		0
        float offset_z		-85
        float fov_h		30
        float fov_v		30
    }

    string Description1		KourbanDesc1
    string Description2		KourbanDesc2
    string Description3		KourbanDesc3
    string InteractiveType		Teammate
    string RadarDescription		KourbanRadar
    float fov		360
    float health		1000
    float playerhatemodifier		0
    float visiondistance		1200
    string Model		char/hazardteam_kourban.tik
    float PainChance		1
}

OBJECT HazardTeamMunro		HazardTeam
{
    string Description1		MunroDesc1
    string Description2		MunroDesc2
    string Description3		MunroDesc3
    string InteractiveType		Teammate
    float RadarDescription		1
    float fov		360
    float health		1000
    float playerhatemodifier		0
    float visiondistance		1200
    float PainChance		1
}

OBJECT HazardTeamSydney		HazardTeam
{
    OBJECT ModelRendering		Rendering
    {
        float angles_pitch		0
        float angles_roll		0
        float angles_yaw		180
        float offset_x		28
        float offset_y		0
        float offset_z		-85
        float fov_h		30
        float fov_v		30
    }

    string Description1		SydneyDesc1
    string Description2		SydneyDesc2
    string Description3		SydneyDesc3
    string InteractiveType		Teammate
    string RadarDescription		SydneyRadar
    float fov		360
    float health		1000
    float playerhatemodifier		0
    float visiondistance		1200
    string Model		char/hazardteam_sydney.tik
    float PainChance		1
}

OBJECT HazardTeamTelsia		HazardTeam
{
    OBJECT ModelRendering		Rendering
    {
        float angles_pitch		0
        float angles_roll		0
        float angles_yaw		180
        float offset_x		28
        float offset_y		0
        float offset_z		-85
        float fov_h		30
        float fov_v		30
    }

    string Description1		TelsiaDesc1
    string Description2		TelsiaDesc2
    string Description3		TelsiaDesc3
    string InteractiveType		Teammate
    string RadarDescription		TelsiaRadar
    float fov		360
    float health		1000
    float playerhatemodifier		0
    float visiondistance		1200
    string Model		char/hazardteam_telsia.tik
    float PainChance		1
}

OBJECT HumanBaseFemale		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    float Description2		1
    float Description3		1
    string InteractiveType		Enemy
    float RadarDescription		1
    float fov		360
    float health		30
    float playerhatemodifier		1.5
    float visiondistance		1200
    float PainChance		1
}

OBJECT HumanBaseMale		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    float Description2		1
    float Description3		1
    string InteractiveType		Enemy
    float RadarDescription		1
    float fov		360
    float health		30
    float playerhatemodifier		1.5
    float visiondistance		2400
    float PainChance		1
}

OBJECT KlingonBaseFemale		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    float Description2		1
    float Description3		1
    string InteractiveType		Friendly
    float RadarDescription		1
    float fov		360
    float health		30
    float playerhatemodifier		1.5
    float visiondistance		1200
    float PainChance		1
}

OBJECT KlingonBaseMale		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    float Description2		1
    float Description3		1
    string InteractiveType		Friendly
    float RadarDescription		1
    float fov		360
    float health		30
    float playerhatemodifier		1.5
    float visiondistance		1200
    float PainChance		1
}

OBJECT KlingonBossCrane		Boss
{
    string Description1		KlingonBossCraneDesc1
    string Description2		KlingonBossCraneDesc2
    string Description3		KlingonBossCraneDesc3
    string InteractiveType		Enemy
    string RadarDescription		KlingonBossCraneRadar
    float fov		360
    float health		2400
    float playerhatemodifier		1.5
    float visiondistance		6000
    float PainChance		1
}

OBJECT Leviathan		Boss
{
    string Description1		LeviathanDesc1
    string Description2		LeviathanDesc2
    string Description3		LeviathanDesc3
    string InteractiveType		Enemy
    string RadarDescription		LeviathanRadar
    float fov		360
    float health		500
    float playerhatemodifier		1.5
    float visiondistance		1200
    float PainChance		1
}

OBJECT NausicaanBaseMale		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    string Description2		NausicaanMaleDesc2
    string Description3		NausicaanMaleDesc3
    string InteractiveType		Enemy
    string RadarDescription		NausicaanRadar
    float fov		360
    float health		300
    float playerhatemodifier		1.5
    float visiondistance		1200
    float PainChance		1
}

OBJECT RomulanBaseFemale		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    string Description2		RomulanFemaleHoloDesc2
    string Description3		RomulanFemaleHoloDesc3
    string InteractiveType		Enemy
    string RadarDescription		RomulanFemaleHoloRadar
    float fov		360
    float health		30
    float playerhatemodifier		1.5
    float visiondistance		1200
    float PainChance		1
}

OBJECT RomulanBaseMale		Humanoids
{
    OBJECT PainChance		DamageType
    {
        float comp_rifle		0.65
        float disruptor		0.65
        float electric		0.45
        float explosion		1
        float firesword		1
        float gas		1
        float imod_primary		0.85
        float imod_secondary		1
        float melee		1
        float phaser		0.05
        float plasmashotgun		1
        float small_explosion		1
        float sniper		1
        float stasis		1
        float tetryon		1
        float vaporize		1
        float vaporize_comp		0.65
        float vaporize_disruptor		0.65
        float vaporize_photon		1
    }

    float Description1		1
    string Description2		RomulanMaleHoloDesc2
    string Description3		RomulanMaleHoloDesc3
    string InteractiveType		Enemy
    string RadarDescription		RomulanMaleHoloRadar
    float fov		360
    float health		30
    float playerhatemodifier		1.5
    float visiondistance		1200
    float PainChance		1
}

OBJECT RomulanInstallationGuardMale		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    string InteractiveType		Enemy
    float fov		110
    float health		40
    float visiondistance		512
    string Description2		RomulanInstallationGuardMaleDesc2
    string Description3		RomulanInstallationGuardMaleDesc3
    string RadarDescription		RomulanInstallationGuardMaleRadar
    float PainChance		1
}

OBJECT RomulanInstallationGuardFemale		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    string InteractiveType		Enemy
    float fov		110
    float health		40
    float visiondistance		512
    string Description2		RomulanInstallationGuardFemaleDesc2
    string Description3		RomulanInstallationGuardFemaleDesc3
    string RadarDescription		RomulanInstallationGuardFemaleRadar
    float PainChance		1
}

OBJECT RomulanInformant		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    string Description1		RomulanInformantDesc1
    string Description2		RomulanInformantDesc2
    string Description3		RomulanInformantDesc3
    string InteractiveType		Friendly
    string RadarDescription		RomulanInformantRadar
    float PainChance		1
    float health		500
}

OBJECT StarfleetBaseAdultFemale		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    float Description2		1
    float Description3		1
    string InteractiveType		Teammate
    float RadarDescription		1
    float fov		360
    float health		100
    float playerhatemodifier		1.5
    float visiondistance		1200
    float PainChance		1
}

OBJECT StarfleetBaseAdultMale		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    float Description2		1
    float Description3		1
    string InteractiveType		Teammate
    float RadarDescription		1
    float fov		360
    float health		100
    float playerhatemodifier		1.5
    float visiondistance		1200
    float PainChance		1
}

OBJECT StarfleetBaseFemale		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    float Description2		1
    float Description3		1
    string InteractiveType		Teammate
    float RadarDescription		1
    float fov		360
    float health		100
    float playerhatemodifier		1.5
    float visiondistance		1200
    float PainChance		1
}

OBJECT StarfleetBaseMale		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    float Description2		1
    float Description3		1
    string InteractiveType		Teammate
    float RadarDescription		1
    float fov		360
    float health		100
    float playerhatemodifier		1.5
    float visiondistance		1200
    float PainChance		1
}

OBJECT Functionary		NPC
{
    string Description1		FunctionaryDesc1
    string Description2		FunctionaryDesc2
    string Description3		FunctionaryDesc3
    string InteractiveType		Friendly
    string RadarDescription		FunctionaryRadar
    float fov		360
    float health		100
    float playerhatemodifier		1.5
    float visiondistance		1200
    float PainChance		1
}

OBJECT Katarina		NPC
{
    string Description1		KatarinaDesc1
    string Description2		KatarinaDesc2
    string Description3		KatarinaDesc3
    string InteractiveType		Friendly
    string RadarDescription		KatarinaRadar
    float fov		360
    float health		100
    float playerhatemodifier		1.5
    float visiondistance		1200
    float PainChance		1
}

OBJECT Picard		NPC
{
    string Description1		PicardDesc1
    string Description2		PicardDesc2
    string Description3		PicardDesc3
    string InteractiveType		Friendly
    string RadarDescription		PicardRadar
    float fov		360
    float health		100
    float playerhatemodifier		1.5
    float visiondistance		1200
    float PainChance		1
}

OBJECT Tuvok		NPC
{
    string Description1		TuvokDesc1
    string Description2		TuvokDesc2
    string Description3		TuvokDesc3
    string InteractiveType		Friendly
    string RadarDescription		TuvokRadar
    float fov		360
    float health		100
    float playerhatemodifier		1.5
    float visiondistance		1200
    float PainChance		1
}

OBJECT IdryllRebelFemale		IdryllRebel
{
    string Description1		IdryllRebelDesc1
    string Description2		IdryllRebelDesc2
    string Description3		IdryllRebelDesc3
    string InteractiveType		Enemy
    string RadarDescription		IdryllRebelRadar
    float fov		120
    float health		40
    float playerhatemodifier		2.5
    float visiondistance		3600
    float PainChance		1
}

OBJECT IdryllRebelMale		IdryllRebel
{
    string Description1		IdryllRebelDesc1
    string Description2		IdryllRebelDesc2
    string Description3		IdryllRebelDesc3
    string InteractiveType		Enemy
    string RadarDescription		IdryllRebelRadar
    float fov		120
    float health		40
    float playerhatemodifier		1
    float visiondistance		3600
    float PainChance		1
}

OBJECT IdryllFather		NPC
{
    string Description1		InigorDesc1
    string Description2		InigorDesc2
    string Description3		InigorDesc3
    string InteractiveType		Friendly
    string RadarDescription		InigorRadar
    float fov		360
    float health		100
    float playerhatemodifier		1.5
    float visiondistance		1200
    float PainChance		1
}

OBJECT IdryllGirlfriend		NPC
{
    string Description1		KleeyaDesc1
    string Description2		KleeyaDesc2
    string Description3		KleeyaDesc3
    string InteractiveType		Friendly
    string RadarDescription		KleeyaRadar
    float fov		360
    float health		100
    float playerhatemodifier		1.5
    float visiondistance		1200
    float PainChance		1
}

OBJECT IdryllSon		NPC
{
    string Description1		KrindoDesc1
    string Description2		KrindoDesc2
    string Description3		KrindoDesc3
    string InteractiveType		Friendly
    string RadarDescription		KrindoRadar
    float fov		360
    float health		100
    float playerhatemodifier		1.5
    float visiondistance		1200
    float PainChance		1
}

OBJECT HoldBatleth		Animations
{
    string Melee		batleth_combo
    float spreadx		600
    float spready		600
    string Aim		batleth_idle
    string CombatBackpedal		swat_backpedal
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		swat_calm_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string Draw		batleth_ready
    string Fire		batleth_ready
    //string Idle		batleth_idle
    string Idle		idle //[b60025] chrissstrahl - fixed strange behaviour when patrolling or following in all ai with batleth
    string IdleBackpedal		backpedal
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    string PostFire		batleth_idle
    string PreFire		batleth_idle
    string PutAway		batleth_idle
}

OBJECT DallasCrate		FederationEnvironment
{
    string Description1		DallasCrateDesc1
    string Description2		DallasCrateDesc2
    string Description3		DallasCrateDesc3
    string InteractiveType		NonInteractive
    string RadarDescription		DallasCrateRadar
}

OBJECT DallasBarrel		FederationEnvironment
{
    string Description2		DallasBarrelDesc2
    string Description3		DallasBarrelDesc3
    string InteractiveType		NonInteractive
}

OBJECT DoorPanel		FederationEnvironment
{
    string Description1		DoorPanelDesc1
    string Description2		DoorPanelDesc2
    string Description3		DoorPanelDesc3
    string InteractiveType		Usable
    string RadarDescription		DoorPanelRadar
}

OBJECT CaptainsChair		FederationEnvironment
{
    string Description2		CaptainsChairDesc2
    string Description3		CaptainsChairDesc3
    string InteractiveType		NonInteractive
}

OBJECT BridgeChair		FederationEnvironment
{
    string Description2		BridgeChairDesc2
    string Description3		BridgeChairDesc3
    string InteractiveType		NonInteractive
}

OBJECT BridgeChair2		FederationEnvironment
{
    string Description2		BridgeChair2Desc2
    string Description3		BridgeChair3Desc3
    string InteractiveType		NonInteractive
}

OBJECT BridgeConsole1		FederationEnvironment
{
    string Description2		BridgeConsole1Desc2
    string Description3		BridgeConsole1Desc3
    string InteractiveType		NonInteractive
}

OBJECT BridgeConsole3		FederationEnvironment
{
    string Description2		BridgeConsole3Desc2
    string Description3		BridgeConsole3Desc3
    string InteractiveType		NonInteractive
}

OBJECT BridgeConsole4		FederationEnvironment
{
    string Description2		BridgeConsole4Desc2
    string Description3		BridgeConsole4Desc3
    string InteractiveType		NonInteractive
}

OBJECT BridgeConsoleCompass		FederationEnvironment
{
    string Description2		BridgeConsoleCompassDesc2
    string Description3		BridgeConsoleCompassDesc3
    string InteractiveType		NonInteractive
}

OBJECT BridgeConsoleFrontLeft		FederationEnvironment
{
    string Description2		BridgeConsoleFrontLeftDesc2
    string Description3		BridgeConsoleFrontLeftDesc3
    string InteractiveType		NonInteractive
}

OBJECT BridgeConsoleFrontRight		FederationEnvironment
{
    string Description2		BridgeConsoleFrontRightDesc2
    string Description3		BridgeConsoleFrontRightDesc3
    string InteractiveType		NonInteractive
}

OBJECT BridgeConsoleOuterLeft		FederationEnvironment
{
    string Description2		BridgeConsoleOuterLeftDesc2
    string Description3		BridgeConsoleOuterLeftDesc3
    string InteractiveType		NonInteractive
}

OBJECT BridgeConsoleOuterRight		FederationEnvironment
{
    string Description2		BridgeConsoleOuterRightDesc2
    string Description3		BridgeConsoleOuterRightDesc3
    string InteractiveType		NonInteractive
}

OBJECT BridgeConsoleRear		FederationEnvironment
{
    string Description2		BridgeConsoleRearDesc2
    string Description3		BridgeConsoleRearDesc3
    string InteractiveType		NonInteractive
}

OBJECT EnterpriseContainer1		FederationEnvironment
{
    string Description2		EnterpriseContainer1Desc2
    string Description3		EnterpriseContainer1Desc3
    string InteractiveType		NonInteractive
}

OBJECT EnterpriseContainer2		FederationEnvironment
{
    string Description2		EnterpriseContainer2Desc2
    string Description3		EnterpriseContainer2Desc3
    string InteractiveType		Destructable
    string Description1		EnterpriseContainer2Desc1
    string RadarDescription		EnterpriseContainer2Radar
}

OBJECT EnterpriseContainer3		FederationEnvironment
{
    string Description2		EnterpriseContainer3Desc2
    string Description3		EnterpriseContainer3Desc3
    string InteractiveType		NonInteractive
}

OBJECT EnterpriseContainer4		FederationEnvironment
{
    string Description2		EnterpriseContainer4Desc2
    string Description3		EnterpriseContainer4Desc3
    string InteractiveType		NonInteractive
}

OBJECT EnterpriseCompTerminal		FederationEnvironment
{
    string Description2		EnterpriseCompTerminalDesc2
    string Description3		EnterpriseCompTerminalDesc3
    string InteractiveType		NonInteractive
}

OBJECT EnterpriseCompStation		FederationEnvironment
{
    string Description2		EnterpriseCompStationDesc2
    string Description3		EnterpriseCompStationDesc3
    string InteractiveType		NonInteractive
}

OBJECT EnterpriseDatapad		FederationEnvironment
{
    string Description2		EnterpriseDatapadDesc2
    string Description3		EnterpriseDatapadDesc3
    string InteractiveType		NonInteractive
}

OBJECT EnterpriseReplicator		FederationEnvironment
{
    string Description2		EnterpriseReplicatorDesc2
    string Description3		EnterpriseReplicatorDesc3
    string InteractiveType		NonInteractive
}

OBJECT EnterpriseLaptop		FederationEnvironment
{
    string Description2		EnterpriseLaptopDesc2
    string Description3		EnterpriseLaptopDesc3
    string InteractiveType		NonInteractive
}

OBJECT ReadyRoomDesk		FederationEnvironment
{
    string Description2		ReadyRoomDeskDesc2
    string Description3		ReadyRoomDeskDesc3
    string InteractiveType		NonInteractive
}

OBJECT ReadyRoomShell		FederationEnvironment
{
    string Description2		ReadyRoomShellDesc2
    string Description3		ReadyRoomShellDesc3
    string InteractiveType		NonInteractive
}

OBJECT ReadyRoomVase		FederationEnvironment
{
    string Description2		ReadyRoomVaseDesc2
    string Description3		ReadyRoomVaseDesc3
    string InteractiveType		NonInteractive
}

OBJECT ReadyRoomChair		FederationEnvironment
{
    string Description2		ReadyRoomChairDesc2
    string Description3		ReadyRoomChairDesc3
    string InteractiveType		NonInteractive
}

OBJECT EnterpriseBed		FederationEnvironment
{
    string Description2		EnterpriseBedDesc2
    string Description3		EnterpriseBedDesc3
    string InteractiveType		NonInteractive
}

OBJECT EnterpriseBench		FederationEnvironment
{
    string Description2		EnterpriseBenchDesc2
    string Description3		EnterpriseBenchDesc3
    string InteractiveType		NonInteractive
}

OBJECT EnterpriseChair1		FederationEnvironment
{
    string Description2		EnterpriseChair1Desc2
    string Description3		EnterpriseChair1Desc3
    string InteractiveType		NonInteractive
}

OBJECT EnterpriseChair2		FederationEnvironment
{
    string Description2		EnterpriseChair2Desc2
    string Description3		EnterpriseChair2Desc3
    string InteractiveType		NonInteractive
}

OBJECT EnterpriseChair3		FederationEnvironment
{
    string Description2		EnterpriseChair3Desc2
    string Description3		EnterpriseChair3Desc3
    string InteractiveType		NonInteractive
}

OBJECT EnterpriseOfficeChair		FederationEnvironment
{
    string Description2		EnterpriseOfficeChairDesc2
    string Description3		EnterpriseOfficeChairDesc3
    string InteractiveType		NonInteractive
}

OBJECT EnterpriseStool		FederationEnvironment
{
    string Description2		EnterpriseStoolDesc2
    string Description3		EnterpriseStoolDesc3
    string InteractiveType		NonInteractive
}

OBJECT ShuttleBayConsole		FederationEnvironment
{
    string Description2		EnterpriseShuttleBayConsoleDesc2
    string Description3		EnterpriseShuttleBayConsoleDesc3
    string InteractiveType		NonInteractive
}

OBJECT SickbayCart		FederationEnvironment
{
    string Description2		SickbayCartDesc2
    string Description3		SickbayCartDesc3
    string InteractiveType		NonInteractive
}

OBJECT SickbayTool1		FederationEnvironment
{
    string Description2		SickbayTool1Desc2
    string Description3		SickbayTool1Desc3
    string InteractiveType		NonInteractive
}

OBJECT SickbayTool2		FederationEnvironment
{
    string Description2		SickbayTool2Desc2
    string Description3		SickbayTool2Desc3
    string InteractiveType		NonInteractive
}

OBJECT SickbayBed		FederationEnvironment
{
    string Description2		SickbayBedDesc2
    string Description3		SickbayBedDesc3
    string InteractiveType		NonInteractive
}

OBJECT EnterpriseTableShelf		FederationEnvironment
{
    string Description2		EnterpriseTableShelfDesc2
    string Description3		EnterpriseTableShelfDesc3
    string InteractiveType		NonInteractive
}

OBJECT EnterpriseTable1		FederationEnvironment
{
    string Description2		EnterpriseTable1Desc2
    string Description3		EnterpriseTable1Desc3
    string InteractiveType		NonInteractive
}

OBJECT EnterpriseTable2		FederationEnvironment
{
    string Description2		EnterpriseTable2Desc2
    string Description3		EnterpriseTable2Desc3
    string InteractiveType		NonInteractive
}

OBJECT EnterpriseTable3		FederationEnvironment
{
    string Description2		EnterpriseTable3Desc2
    string Description3		EnterpriseTable3Desc3
    string InteractiveType		NonInteractive
}

OBJECT EnterpriseTable4		FederationEnvironment
{
    string Description2		EnterpriseTable4Desc2
    string Description3		EnterpriseTable4Desc3
    string InteractiveType		NonInteractive
}

OBJECT AcademyCup1		FederationEnvironment
{
    string Description2		AcademyCup1Desc2
    string Description3		AcademyCup1Desc3
    string InteractiveType		NonInteractive
}

OBJECT AcademyLamp1		FederationEnvironment
{
    string Description2		AcademyLamp1Desc2
    string Description3		AcademyLamp1Desc3
    string InteractiveType		NonInteractive
}

OBJECT AcademyPicture1		FederationEnvironment
{
    string Description2		AcademyPicture1Desc2
    string Description3		AcademyPicture1Desc3
    string InteractiveType		NonInteractive
}

OBJECT AttrexianCart		AttrexianEnvironment
{
    string InteractiveType		NonInteractive
    string Description1		AttrexianCartDesc1
    string Description2		AttrexianCartDesc2
    string Description3		AttrexianCartDesc3
    string RadarDescription		AttrexianCartRadar
}

OBJECT AttrexianLiftControl		AttrexianEnvironment
{
    string InteractiveType		Usable
    string Description2		AttrexianLiftControlDesc2
    string Description3		AttrexianLiftControlDesc3
    string Description1		AttrexianLiftControlDesc1
    string RadarDescription		AttrexianLiftControlRadar
}

OBJECT AttrexianCartControl		AttrexianEnvironment
{
    string InteractiveType		Usable
    string Description1		AttrexianCartControlDesc1
    string Description2		AttrexianCartControlDesc2
    string Description3		AttrexianCartControlDesc3
    string RadarDescription		AttrexianCartControlRadar
}

OBJECT AttrexianSecurityPanel		AttrexianEnvironment
{
    string InteractiveType		Usable
    string Description1		AttrexianSecurityPanelDesc1
    string Description2		AttrexianSecurityPanelDesc2
    string Description3		AttrexianSecurityPanelDesc3
    string RadarDescription		SecurityPanelRadar
}

OBJECT AttrexianCrate		AttrexianEnvironment
{
    string Description2		AttrexianCrateDesc2
    string Description3		AttrexianCrateDesc3
    string InteractiveType		NonInteractive
}

OBJECT AttrexianComputerPanel		AttrexianEnvironment
{
    string Description2		AttrexianComputerPanelDesc2
    string Description3		AttrexianComputerPanelDesc3
    string InteractiveType		NonInteractive
}

OBJECT AttrexianDoorPanel		AttrexianEnvironment
{
    string Description1		AttrexianDoorPanelDesc1
    string Description2		AttrexianDoorPanelDesc2
    string Description3		AttrexianDoorPanelDesc3
    string InteractiveType		Usable
    string RadarDescription		AttrexianDoorPanelRadar
}

OBJECT AttrexianChair		AttrexianEnvironment
{
    string Description2		AttrexianChairDesc2
    string Description3		AttrexianChairDesc3
    string InteractiveType		NonInteractive
}

OBJECT IdryllLargeContainer		IdryllEnvironment
{
    string Description2		IdryllLargeContainerDesc2
    string Description3		IdryllLargeContainerDesc3
    string InteractiveType		NonInteractive
    string Description1		IdryllLargeContainerDesc1
    string RadarDescription		IdryllLargeContainerRadar
}

OBJECT IdryllMedContainer		IdryllEnvironment
{
    string Description2		IdryllMedContainerDesc2
    string Description3		IdryllMedContainerDesc3
    string InteractiveType		NonInteractive
    string RadarDescription		IdryllMedContainerRadar
}

OBJECT IdryllSmallContainer		IdryllEnvironment
{
    string Description2		IdryllSmallContainerDesc2
    string Description3		IdryllSmallContainerDesc3
    string InteractiveType		NonInteractive
    string RadarDescription		IdryllSmallContainerRadar
}

OBJECT IdryllLamp		IdryllEnvironment
{
    string Description2		IdryllLampDesc2
    string Description3		IdryllLampDesc3
    string InteractiveType		NonInteractive
}

OBJECT IdryllMoistVap		IdryllEnvironment
{
    string Description2		IdryllMoistVapDesc2
    string Description3		IdryllMoistVapDesc3
    string InteractiveType		NonInteractive
}

OBJECT IdryllMoistVapLarge		IdryllEnvironment
{
    string Description2		IdryllMoistVapLargeDesc2
    string Description3		IdryllMoistVapDesc3
    string InteractiveType		NonInteractive
}

OBJECT IdryllMoistVapMed		IdryllEnvironment
{
    string Description2		IdryllMoistVapMedDesc2
    string Description3		IdryllMoistVapDescMedDesc3
    string InteractiveType		NonInteractive
}

OBJECT IdryllPlant1		IdryllEnvironment
{
    string Description2		IdryllPlant1Desc2
    string Description3		IdryllPlant1Desc3
    string InteractiveType		NonInteractive
}

OBJECT IdryllPlant2		IdryllEnvironment
{
    string Description2		IdryllPlant2Desc2
    string Description3		IdryllPlant2Desc3
    string InteractiveType		NonInteractive
}

OBJECT KlingonCrate1		KlingonEnvironment
{
    string Description2		KlingonCrate1Desc2
    string Description3		KlingonCrate1Desc3
    string InteractiveType		NonInteractive
}

OBJECT KlingonCrate2		KlingonEnvironment
{
    string Description2		KlingonCrate2Desc2
    string Description3		KlingonCrate2Desc3
    string InteractiveType		Destructable
    string Description1		KlingonCrate2Desc1
}

OBJECT RomulanConsole		RomulanEnvironment
{
    string Description2		RomulanConsoleDesc2
    string Description3		RomulanConsoleDesc3
    string Description1		RomulanConsoleDesc1
    string InteractiveType		TricorderUsable
    string RadarDescription		RomulanConsoleRadar
}

OBJECT HoldGatGun		Animations
{
    string Aim		tetryon_aim
    string Draw		tetryon_draw
    string Fire		tetryon_fire
    string Idle		tetryon_idle
    string Melee		tetryon_melee
    string PostFire		tetryon_postfire
    string PreFire		tetryon_prefire
    string PutAway		tetryon_putaway
    string CombatGunIdle		tetryon_tense_idle
    string IdleGunIdle		tetryon_calm_idle
    string CombatBackpedal		swat_backpedal
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		swat_calm_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string IdleBackpedal		backpedal
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    float AimTimeMax		0.3
    float AimTimeMin		0.25
    float FireTimeMax		2.5
    float FireTimeMin		2
    float spreadx		300
    float spready		300
}

OBJECT KlingonMercBoss		Boss
{
    string InteractiveType		Enemy
    float fov		360
    float health		600
    float playerhatemodifier		1
    float visiondistance		4096
    float PainChance		1
    string Description1		KlingonMercBossDesc1
    string Description2		KlingonMercBossDesc2
    string Description3		KlingonMercBossDesc3
    string RadarDescription		KlingonMercRadar
}

OBJECT AttrexianLiftPower		AttrexianEnvironment
{
    string Description2		AttrexianLiftPowerDesc2
    string Description3		AttrexianLiftPowerDesc3
    string InteractiveType		Usable
    string Description1		AttrexianLiftPowerDesc1
    string RadarDescription		AttrexianLiftPowerRadar
}

OBJECT AttrexianPodPanel		AttrexianEnvironment
{
    string Description2		AttrexianPodPanelDesc2
    string Description3		AttrexianPodPanelDesc3
    string InteractiveType		Usable
    string Description1		AttrexianPodPanelDesc1
    string RadarDescription		AttrexianPodPanelRadar
}

OBJECT AttrexianCartPanel		AttrexianEnvironment
{
    string Description2		AttrexianCartPanelDesc2
    string Description3		AttrexianCartPanelDesc3
    string InteractiveType		Usable
    string Description1		AttrexianCartPanelDesc1
    string RadarDescription		AttrexianCartPanelRadar
}

OBJECT AttrexianCartLever		AttrexianEnvironment
{
    string Description2		AttrexianCartLeverDesc2
    string Description3		AttrexianCartLeverDesc3
    string InteractiveType		TricorderUsable
    string Description1		AttrexianCartLeverDesc1
    string RadarDescription		AttrexianCartLeverRadar
}

OBJECT KlingonDoorPanel		KlingonEnvironment
{
    string Description2		KlingonDoorPanelDesc2
    string Description3		KlingonDoorPanelDesc3
    string InteractiveType		Usable
    string Description1		KlingonDoorPanelDesc1
    string RadarDescription		KlingonDoorPanelRadar
}

OBJECT BorgLiftPanel		BorgEnvironment
{
    string Description1		BorgLiftPanelDesc1
    string Description2		BorgLiftPanelDesc2
    string Description3		BorgLiftPanelDesc3
    string InteractiveType		Usable
    string RadarDescription		BorgLiftPanelRadar
}

OBJECT DampeningField		BorgEnvironment
{
    string Description1		DampeningFieldDesc1
    string Description2		DampeningFieldDesc2
    string Description3		DampeningFieldDesc3
    string InteractiveType		TricorderUsable
    string RadarDescription		DampeningFieldRadar
}

OBJECT RomulanDoorPanel		RomulanEnvironment
{
    string Description1		RomulanDoorPanelDesc1
    string Description2		RomulanDoorPanelDesc2
    string Description3		RomulanDoorPanelDesc3
    string InteractiveType		Usable
    string RadarDescription		RomulanDoorPanelRadar
}

OBJECT RomulanCrate		RomulanEnvironment
{
    string Description2		RomulanCrateDesc2
    string Description3		RomulanCrateDesc3
    string InteractiveType		NonInteractive
}

OBJECT AttrexianPowerPanel		AttrexianEnvironment
{
    string Description1		AttrexianPowerPanelDesc1
    string Description2		AttrexianPowerPanelDesc2
    string Description3		AttrexianPowerPanelDesc3
    string InteractiveType		TricorderUsable
    string RadarDescription		AttrexianPowerPanelRadar
}

OBJECT SkillLevel-PlayerDamage		SkillLevel
{
    float Easy		0.5
    float Normal		1
    float Hard		3
    float VeryHard		6
}

OBJECT ExteriorTricorderPanel		FederationEnvironment
{
    string Description3		ExteriorTricorderPanelDesc3
    string Description2		ExteriorTricorderPanelDesc2
    string InteractiveType		Usable
}

OBJECT HoldAndorianGrenadeLauncher		Animations
{
    string Aim		andoriangrenadelauncher_aim
    string Draw		andoriangrenadelauncher_draw
    string Fire		andoriangrenadelauncher_fire
    string Idle		andoriangrenadelauncher_calm_idle
    string Melee		andoriangrenadelauncher_melee
    string PostFire		andoriangrenadelauncher_postfire
    string PreFire		andoriangrenadelauncher_prefire
    string PutAway		andoriangrenadelauncher_putaway
    string CombatGunIdle		andoriangrenadelauncher_tense_idle
    string IdleGunIdle		andoriangrenadelauncher_calm_idle
    float CombatBackpedal		1
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		swat_calm_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string IdleBackpedal		backpedal
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    float AimTimeMax		1.75
    float AimTimeMin		1.25
    float FireTimeMax		-1
    float FireTimeMin		-1
    float spreadx		0
    float spready		0
    float ShotCount		1
}

OBJECT HoldAndorianPhotonBurst		Animations
{
    string Draw		andorianphotonburst_draw
    string Aim		andorianphotonburst_aim
    string Fire		andorianphotonburst_fire
    string Idle		andorianphotonburst_calm_idle
    string Melee		andorianphotonburst_melee
    string PostFire		andorianphotonburst_postfire
    string PreFire		andorianphotonburst_prefire
    string PutAway		andorianphotonburst_putaway
    string CombatGunIdle		andorianphotonburst_tense_idle
    string IdleGunIdle		andorianphotonburst_calm_idle
    string CombatBackpedal		swat_backpedal
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		swat_calm_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string IdleBackpedal		backpedal
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    float AimTimeMax		-1
    float AimTimeMin		-1
    float FireTimeMax		-1
    float FireTimeMin		-1
    float spreadx		0
    float spready		0
}

OBJECT HoldAttrexianRifle		Animations
{
    string Aim		attrexrifle_aim
    string Draw		attrexrifle_draw
    string Fire		attrexrifle_fire
    string Idle		attrexrifle_calm_idle1
    string Melee		attrexrifle_melee
    string PostFire		attrexrifle_postfire
    string PreFire		attrexrifle_prefire
    string PutAway		attrexrifle_putaway
    string CombatGunIdle		attrexrifle_tense_idle
    string IdleGunIdle		attrexrifle_calm_idle
    string CombatBackpedal		swat_backpedal
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		swat_calm_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string IdleBackpedal		backpedal
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    float AimTimeMax		0.3
    float AimTimeMin		0.25
    float FireTimeMax		1.25
    float FireTimeMin		1
    float spreadx		600
    float spready		600
    float ShotCount		50
}

OBJECT HoldHumanShotgun		Animations
{
    string Aim		humanshotgun_aim
    string Draw		humanshotgun_draw
    string Fire		humanshotgun_fire
    string Idle		humanshotgun_calm_idle
    string Melee		humanshotgun_melee
    string PostFire		humanshotgun_postfire
    string PreFire		humanshotgun_prefire
    string PutAway		humanshotgun_putaway
    string CombatGunIdle		humanshotgun_tense_idle
    string IdleGunIdle		humanshotgun_calm_idle
    string CombatBackpedal		swat_backpedal
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		swat_calm_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string IdleBackpedal		backpedal
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    float AimTimeMax		0.3
    float AimTimeMin		0.25
    float FireTimeMax		1.25
    float FireTimeMin		1
    float spreadx		600
    float spready		600
}

OBJECT HoldKlingonDisruptorRifle		Animations
{
    string Draw		klidisruptorrifle_draw
    string Aim		klidisruptorrifle_aim
    string Fire		klidisruptorrifle_fire
    string Idle		klidisruptorrifle_calm_idle
    string Melee		klidisruptorrifle_melee
    string PostFire		klidisruptorrifle_postfire
    string PreFire		klidisruptorrifle_prefire
    string PutAway		klidisruptorrifle_putaway
    string CombatGunIdle		klidisruptorrifle_tense_idle
    string IdleGunIdle		klidisruptorrifle_calm_idle
    string CombatBackpedal		swat_backpedal
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		swat_calm_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string IdleBackpedal		backpedal
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    float AimTimeMax		0.35
    float AimTimeMin		0.2
    float FireTimeMax		-1
    float FireTimeMin		-1
    float spreadx		50
    float spready		50
    float ShotCount		5
}

OBJECT HoldRomulanPhotonBurst		Animations
{
    string Aim		romulanphotonburst_aim
    string Draw		romulanphotonburst_draw
    string Fire		romulanphotonburst_fire
    string Idle		romulanphotonburst_calm_idle1
    string Melee		romulanphotonburst_melee
    string PostFire		romulanphotonburst_postfire
    string PreFire		romulanphotonburst_prefire
    string PutAway		romulanphotonburst_putaway
    string CombatGunIdle		romulanphotonburst_tense_idle
    string IdleGunIdle		romulanphotonburst_calm_idle
    string CombatBackpedal		swat_backpedal
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		swat_calm_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string IdleBackpedal		backpedal
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    float AimTimeMax		-1
    float AimTimeMin		-1
    float FireTimeMax		-1
    float FireTimeMin		-1
    float spreadx		0
    float spready		0
}

OBJECT HoldRomulanGrenadeLauncher		Animations
{
    string Aim		romulangrenadelauncher_aim
    string Draw		romulangrenadelauncher_draw
    string Fire		romulangrenadelauncher_fire
    string Idle		romulangrenadelauncher_calm_idle1
    string Melee		romulangrenadelauncher_melee
    string PostFire		romulangrenadelauncher_postfire
    string PreFire		romulangrenadelauncher_prefire
    string PutAway		romulangrenadelauncher_putaway
    string CombatGunIdle		romulangrenadelauncher_tense_idle
    string IdleGunIdle		romulangrenadelauncher_calm_idle
    string CombatBackpedal		swat_backpedal
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		swat_calm_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string IdleBackpedal		backpedal
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    float AimTimeMax		2
    float AimTimeMin		1.25
    float FireTimeMax		-1
    float FireTimeMin		-1
    float spreadx		0
    float spready		0
}

OBJECT HoldRomulanDisruptorRifle		Animations
{
    string Aim		romulandisruptorrifle_aim
    string Draw		romulandisruptorrifle_draw
    string Fire		romulandisruptorrifle_fire
    string Idle		romulandisruptorrifle_calm_idle1
    string Melee		romulandisruptorrifle_melee
    string PostFire		romulandisruptorrifle_postfire
    string PreFire		romulandisruptorrifle_prefire
    string PutAway		romulandisruptorrifle_putaway
    string CombatGunIdle		romulandisruptorrifle_tense_idle
    string IdleGunIdle		romulandisruptorrifle_calm_idle
    string CombatBackpedal		swat_backpedal
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		swat_calm_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string IdleBackpedal		backpedal
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    float AimTimeMax		0.3
    float AimTimeMin		0.25
    float FireTimeMax		1
    float FireTimeMin		0.75
    float spreadx		50
    float spready		50
    float ShotCount		3
}

OBJECT HoldRomulanSniperRifle		Animations
{
    string Aim		romsniperrifle_aim
    string Draw		romsniperrifle_draw
    string Fire		romsniperrifle_fire
    string Idle		romsniperrifle_calm_idle
    string Melee		romsniperrifle_melee
    string PostFire		romsniperrifle_postfire
    string PreFire		romsniperrifle_prefire
    string PutAway		romsniperrifle_putaway
    string CombatGunIdle		romsniperrifle_tense_idle
    string IdleGunIdle		romsniperrifle_calm_idle
    string CombatBackpedal		swat_backpedal
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		swat_calm_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string IdleBackpedal		backpedal
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    float AimTimeMax		0.85
    float AimTimeMin		0.65
    float FireTimeMax		-1
    float FireTimeMin		-1
    float InitialSpreadX		3000
    float InitialSpreadY		3000
    float SpreadMultiplier		0.85
    float spreadx		15
    float spready		15
}

OBJECT HoldKnife		Animations
{
    string Melee		knife_combo
    float spreadx		600
    float spready		600
}

OBJECT HoldPhotonBurst		Animations
{
    string Aim		photonburst_aim
    string Draw		photonburst_draw
    string Fire		photonburst_fire
    string Idle		photonburst_calm_idle
    string Melee		photonburst_melee
    string PostFire		photonburst_postfire
    string PreFire		photonburst_prefire
    string PutAway		photonburst_putaway
    string CombatGunIdle		photonburst_tense_idle
    string IdleGunIdle		photonburst_calm_idle
    string CombatBackpedal		swat_backpedal
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		swat_calm_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string IdleBackpedal		backpedal
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    float AimTimeMin		-1
    float AimTimeMax		-1
    float FireTimeMax		-1
    float FireTimeMin		-1
    float spreadx		0
    float spready		0
}

OBJECT HoldGrenadeLauncher		Animations
{
    string Aim		grenadelauncher_aim
    string Draw		grenadelauncher_draw
    string Fire		grenadelauncher_fire
    string Idle		grenadelauncher_calm_idle
    string Melee		grenadelauncher_melee
    string PostFire		grenadelauncher_postfire
    string PreFire		grenadelauncher_prefire
    string PutAway		grenadelauncher_putaway
    string CombatGunIdle		grenadelauncher_tense_idle
    string IdleGunIdle		grenadelauncher_calm_idle
    string CombatBackpedal		swat_backpedal
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		swat_calm_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string IdleBackpedal		backpedal
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    string IdleRStrafe		strafe_right
    float IdleRun		1
    string IdleWalk		walk
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    float AimTimeMax		-1
    float AimTimeMin		-1
    float FireTimeMax		-1
    float FireTimeMin		-1
    float spreadx		0
    float spready		0
    float InitialSpreadX		1
}

OBJECT HoldIdryllEliteGauntletWithShield		Animations
{
    string Aim		gauntlet_ffshield_idle
    float AimTimeMax		-1
    float AimTimeMin		-1
    string CombatBackpedal		swat_backpedal
    string CombatGunIdle		defensive_hold
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		swat_calm_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string Draw		gauntlet_ffshield_draw
    string Fire		gauntlet_ffshield_fire
    float FireTimeMax		-1
    float FireTimeMin		1
    string Idle		gauntlet_ffshield_idle
    string IdleBackpedal		backpedal
    string IdleGunIdle		idle
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    string PostFire		gauntlet_ffshield_postfire
    string PreFire		gauntlet_ffshield_prefire
    string PutAway		gauntlet_ffshield_putaway
    float spreadx		150
    float spready		150
    float InitialSpreadX		1
    float InitialSpreadY		1
    string Melee		meleecombo
    float SpreadMultiplier		1
}

OBJECT HoldIdryllEliteGauntletNoShield		Animations
{
    string Aim		gauntlet_noshield_idle
    float AimTimeMax		-1
    float AimTimeMin		-1
    string CombatBackpedal		swat_backpedal
    string CombatGunIdle		defensive_hold
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		swat_calm_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string Draw		gauntlet_noshield_draw
    string Fire		gauntlet_noshield_fire
    float FireTimeMax		-1
    float FireTimeMin		-1
    string Idle		gauntlet_noshield_idle
    string IdleBackpedal		backpedal
    string IdleGunIdle		idle
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    float IdleWalk		1
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    string PostFire		gauntlet_shield_postfire
    string PreFire		gauntlet_shield_prefire
    string PutAway		gauntlet_shield_putaway
    float spreadx		75
    float spready		75
}

OBJECT PainChance		DamageType
{
    float phaser		0.02
    float vaporize		1
    float comp_rifle		0.65
    float vaporize_comp		0.65
    float imod_primary		0.85
    float imod_secondary		1
    float plasmashotgun		1
    float small_explosion		1
    float electric		0.45
    float gas		1
    float stasis		1
    float explosion		1
    float tetryon		1
    float disruptor		0.65
    float vaporize_disruptor		0.65
    float firesword		1
    float sniper		1
    float melee		1
    float vaporize_photon		1
}

OBJECT FadeOutPhoton		DisplayEffects
{
    string EffectName		fx/fx-fadeout-photon.tik
    string EffectPosName		randombone
    float EffectTime		1.5
    float FadeTime		2
    float NumEffects		11
    string ShaderName		photon_death
    string SoundName		snd_phaserdeath
    float Immobilize		1
    float AttachEffect		1
    float HideFeatures		0
}

OBJECT ReflectionModel-phaser		ModelAliases
{
    string ModelName		models/fx/fx-shieldimpact-idryll-phaser.tik
}

OBJECT ReflectionModel-default		ModelAliases
{
    string ModelName		models/fx/fx-shieldimpact-idryll-default.tik
}

OBJECT HoldIdryllGauntletSniper		Animations
{
    float AimTimeMax		2.5
    float AimTimeMin		2
    string CombatBackpedal		swat_backpedal
    string CombatGunIdle		idle
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		swat_calm_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string Draw		gauntlet_sniper_draw
    string Fire		gauntlet_sniper_fire
    float FireTimeMax		-1
    float FireTimeMin		-1
    string Idle		gauntlet_sniper_aim
    string IdleBackpedal		backpedal
    string IdleGunIdle		gauntlet_sniper_aim
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    string Melee		MeleeCombo
    string PostFire		gauntlet_sniper_postfire
    float PreFire		1
    string PutAway		gauntlet_sniper_putaway
    float SpreadMultiplier		0.85
    string Aim		gauntlet_sniper_aim
    float spreadx		0
    float spready		0
}

OBJECT IdryllBridgeSwitch		IdryllEnvironment
{
    string Description2		IdryllBridgeSwitchDesc2
    string Description3		IdryllBridgeSwitchDesc3
    string InteractiveType		Usable
    string Description1		IdryllBridgeSwitchDesc1
    string RadarDescription		BridgeSwitchRadar
}

OBJECT IdryllPowerRegulator		IdryllEnvironment
{
    string Description1		IdryllPowerRegulatorDesc1
    string Description2		IdryllPowerRegulatorDesc2
    string Description3		IdryllPowerRegulatorDesc3
    string InteractiveType		TricorderUsable
    string RadarDescription		IdryllPowerRegulatorRadar
}

OBJECT Multiplayer		UI
{
    string MapScreenShot		EMPTY
    string MapList		EMPTY
    string BotList		EMTPY
    string MapName		EMPTY
    string MapAward		EMPTY
    float EnableAddFavoritesButton		0
    float EnableDelFavoritesButton		0
}

OBJECT KlingonDoorJunction		KlingonEnvironment
{
    string Description1		KlingonDoorJunctionDesc1
    string Description2		KlingonDoorJunctionDesc2
    string Description3		KlingonDoorJunctionDesc3
    string InteractiveType		TricorderUsable
}

OBJECT KlingonConduit		KlingonEnvironment
{
    string InteractiveType		Destructable
    string Description1		KlingonConduitDesc1
    string Description2		KlingonConduitDesc2
    string Description3		KlingonConduitDesc3
}

OBJECT KlingonCrate3		KlingonEnvironment
{
    string Description1		KlingonCrate3Desc1
    string Description2		KlingonCrate3Desc2
    string Description3		KlingonCrate3Desc3
    string InteractiveType		Destructable
}

OBJECT HoldIdryllFFGauntletWithShield		Animations
{
    string Aim		gauntlet_ffshield_idle
    float AimTimeMax		-1
    float AimTimeMin		-1
    string CombatBackpedal		swat_backpedal
    string CombatGunIdle		defensive_hold
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		swat_calm_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string Draw		gauntlet_ffshield_draw
    string Fire		gauntlet_ffshield_fire
    float FireTimeMax		-1
    float FireTimeMin		-1
    string Idle		gauntlet_ffshield_idle
    string IdleBackpedal		backpedal
    string IdleGunIdle		idle
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    string PostFire		gauntlet_ffshield_postfire
    string PreFire		gauntlet_ffshield_prefire
    string PutAway		gauntlet_ffshield_putaway
    float spreadx		200
    float spready		200
    float InitialSpreadX		1
    float InitialSpreadY		1
    string Melee		meleecombo
    float SpreadMultiplier		1
}

OBJECT HoldIdryllFFGauntletNoShield		Animations
{
    string Aim		gauntlet_ffnoshield_idle
    float AimTimeMax		-1
    float AimTimeMin		-1
    string CombatBackpedal		swat_backpedal
    string CombatGunIdle		defensive_hold
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		swat_calm_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string Draw		gauntlet_ffnoshield_draw
    string Fire		gauntlet_ffnoshield_fire
    float FireTimeMax		-1
    float FireTimeMin		-1
    string Idle		gauntlet_ffnoshield_idle
    string IdleBackpedal		backpedal
    string IdleGunIdle		idle
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    float PostFire		1
    string PreFire		gauntlet_ffnoshield_prefire
    string PutAway		gauntlet_ffnoshield_putaway
    float spreadx		200
    float spready		200
    float InitialSpreadX		1
    float InitialSpreadY		1
    string Melee		melee_noshield-combo
    float SpreadMultiplier		1
}

OBJECT KlingonHealthTerminal		KlingonEnvironment
{
    string Description1		KlingonHealthTerminalDesc1
    string Description2		KlingonHealthTerminalDesc2
    string Description3		KlingonHealthTerminalDesc3
    string InteractiveType		Usable
    string RadarDescription		HealthTerminalRadar
}

OBJECT KlingonEnergyTerminal		KlingonEnvironment
{
    string Description1		KlingonEnergyTerminalDesc1
    string Description2		KlingonEnergyTerminalDesc2
    string Description3		KlingonEnergyTerminalDesc3
    string InteractiveType		Usable
    string RadarDescription		EnergyTerminalRadar
}

OBJECT AttrexianEnergyTerminal		AttrexianEnvironment
{
    string Description1		AttrexianEnergyTerminalDesc1
    string Description2		AttrexianEnergyTerminalDesc2
    string Description3		AttrexianEnergyTerminalDesc3
    string InteractiveType		Usable
    string RadarDescription		EnergyTerminalRadar
}

OBJECT AttrexianHealthTerminal		AttrexianEnvironment
{
    string Description1		AttrexianHealthTerminalDesc1
    string Description2		AttrexianHealthTerminalDesc2
    string Description3		AttrexianHealthTerminalDesc3
    string InteractiveType		Usable
    string RadarDescription		HealthTerminalRadar
}

OBJECT RomulanEnergyTerminal		RomulanEnvironment
{
    string Description1		RomulanEnergyTerminalDesc1
    string Description2		RomulanEnergyTerminalDesc2
    string Description3		RomulanEnergyTerminalDesc3
    string InteractiveType		Usable
    string RadarDescription		EnergyTerminalRadar
}

OBJECT IdryllDoorPanel		IdryllEnvironment
{
    string Description1		IdryllDoorPanelDesc1
    string Description2		IdryllDoorPanelDesc2
    string Description3		IdryllDoorPanelDesc3
    string InteractiveType		Usable
    string RadarDescription		IdryllDoorPanelRadar
}

OBJECT IdryllSecurityPanel		IdryllEnvironment
{
    string Description1		IdryllSecurityPanelDesc1
    string Description2		IdryllSecurityPanelDesc2
    string Description3		IdryllSecurityPanelDesc3
    string InteractiveType		Usable
    string RadarDescription		SecurityPanelRadar
}

OBJECT IdryllLiftPanel		IdryllEnvironment
{
    string Description1		IdryllLiftPanelDesc1
    string Description2		IdryllLiftPanelDesc2
    string Description3		IdryllLiftPanelDesc3
    string InteractiveType		Usable
    string RadarDescription		LiftPanelRadar
}

OBJECT IdryllComputerPanel		IdryllEnvironment
{
    string Description1		IdryllComputerPanelDesc1
    string Description2		IdryllComputerPanelDesc2
    string Description3		IdryllComputerPanelDesc3
    string InteractiveType		Usable
    string RadarDescription		ComputerPanelRadar
}

OBJECT IdryllPowerPanel		IdryllEnvironment
{
    string Description1		IdryllPowerPanelDesc1
    string Description2		IdryllPowerPanelDesc2
    string Description3		IdryllPowerPanelDesc3
    string InteractiveType		TricorderUsable
    string RadarDescription		PowerPanelRadar
}

OBJECT IdryllTurret		IdryllEnvironment
{
    string Description1		IdryllTurretDesc1
    string Description2		IdryllTurretDesc2
    string Description3		IdryllTurretDesc3
    string InteractiveType		Destructable
    string RadarDescription		IdryllTurretRadar
}

OBJECT PhaseConverter		FederationEnvironment
{
    string Description1		PhaseConverterDesc1
    string Description2		PhaseConverterDesc2
    string Description3		PhaseConverterDesc3
    string InteractiveType		Usable
    string RadarDescription		PhaseConverterRadar
}

OBJECT HoldIdryllFFEliGauntletNoShield		Animations
{
    string Aim		gauntlet_ffnoshield_idle
    float AimTimeMax		-1
    float AimTimeMin		-1
    string CombatBackpedal		swat_backpedal
    string CombatGunIdle		defensive_hold
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		swat_calm_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string Draw		gauntlet_ffnoshield_draw
    string Fire		gauntlet_ffnoshield_fire
    float FireTimeMax		-1
    float FireTimeMin		-1
    string Idle		gauntlet_ffnoshield_idle
    string IdleBackpedal		backpedal
    string IdleGunIdle		idle
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    float InitialSpreadX		1
    float InitialSpreadY		1
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    float Melee		1
    string PostFire		gauntlet_ffnoshield_postfire
    string PreFire		gauntlet_ffnoshield_prefire
    string PutAway		gauntlet_ffnoshield_putaway
    float SpreadMultiplier		1
    float spreadx		0
    float spready		0
}

OBJECT HoldIdryllFFEliGauntletWithShield		Animations
{
    string Aim		gauntlet_ffshield_idle
    float AimTimeMax		-1
    float AimTimeMin		-1
    string CombatBackpedal		swat_backpedal
    string CombatGunIdle		defensive_hold
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		swat_calm_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string Draw		gauntlet_ffshield_draw
    string Fire		gauntlet_ffshield_fire
    float FireTimeMax		-1
    float FireTimeMin		-1
    string Idle		gauntlet_ffshield_idle
    string IdleBackpedal		backpedal
    string IdleGunIdle		idle
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    float InitialSpreadX		1
    float InitialSpreadY		1
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    string Melee		meleecombo
    string PostFire		gauntlet_ffshield_postfire
    string PreFire		gauntlet_ffshield_prefire
    string PutAway		gauntlet_ffshield_putaway
    float SpreadMultiplier		1
    float spreadx		0
    float spready		0
}

OBJECT RomulanHealthTerminal		RomulanEnvironment
{
    string Description1		RomulanHealthTerminalDesc1
    string Description2		RomulanHealthTerminalDesc2
    string Description3		RomulanHealthTerminalDesc3
    string InteractiveType		Usable
    string RadarDescription		HealthTerminalRadar
}

OBJECT RomulanRebelMale		Humanoids
{
    float Description1		1
    float Description2		1
    float Description3		1
    string InteractiveType		Enemy
    float PainChance		1
    float RadarDescription		1
    float fov		360
    float health		50
    float playerhatemodifier		1.5
    float visiondistance		1200
}

OBJECT RomulanRebelFemale		Humanoids
{
    float Description1		1
    float Description2		1
    float Description3		1
    string InteractiveType		Enemy
    float PainChance		1
    float RadarDescription		1
    float fov		360
    float health		50
    float playerhatemodifier		1.5
    float visiondistance		1200
}

OBJECT TransportInRomulan		DisplayEffects
{
    string EffectName		fx/fx-beamsparkle-romulan.tik
    string EffectPosName		centroid
    float EffectTime		1
    float FadeTime		2
    string ShaderName		transport-romulan
    string SoundName		snd_bodytransportout
    float TransportTime		0.75
    float Immobilize		1
    float AttachEffect		0
    float HideFeatures		1
}

OBJECT RomulanSecuritySign		RomulanEnvironment
{
    string Description2		RomulanSecuritySignDesc2
    float Description3		1
    string InteractiveType		TricorderUsable
    string Description1		RomulanSecuritySignDesc1
}

OBJECT RomulanCommStationSign		RomulanEnvironment
{
    string Description2		RomulanCommStationSignDesc2
    float Description3		1
    string InteractiveType		TricorderUsable
    string Description1		RomulanCommStationSignDesc1
}

OBJECT RomulanCommandSign		RomulanEnvironment
{
    string Description2		RomulanCommandSignDesc2
    float Description3		1
    string InteractiveType		TricorderUsable
    string Description1		RomulanCommandSignDesc1
}

OBJECT RomulanSecurityConsole		RomulanEnvironment
{
    string Description2		RomulanSecurityConsoleDesc2
    string Description3		RomulanSecurityConsoleDesc3
    string Description1		RomulanSecurityConsoleDesc1
    string InteractiveType		TricorderUsable
    string RadarDescription		SecurityConsoleRadar
}

OBJECT RomulanEntranceSign		RomulanEnvironment
{
    string Description2		RomulanEntranceSignDesc2
    float Description3		1
    string InteractiveType		TricorderUsable
    string Description1		RomulanEntranceSignDesc1
}

OBJECT RomulanStorageSign		RomulanEnvironment
{
    string Description2		RomulanStorageSignDesc2
    float Description3		1
    string InteractiveType		TricorderUsable
    string Description1		RomulanStorageSignDesc1
}

OBJECT TransportOutFederationNoAnim		DisplayEffects
{
    string EffectName		fx/fx-beamsparkle.tik
    string EffectPosName		centroid
    float EffectTime		1.25
    string ShaderName		transport
    float TransportTime		1.25
    string SoundName		snd_bodytransportout
    float Immobilize		1
    float AttachEffect		0
    float HideFeatures		1
}

OBJECT TransportInFederationNoAnim		DisplayEffects
{
    string EffectName		fx/fx-beamsparkle.tik
    string EffectPosName		centroid
    float EffectTime		1.25
    string ShaderName		transport
    float TransportTime		1.25
    string SoundName		snd_bodytransportin
    float Immobilize		1
    float AttachEffect		0
    float HideFeatures		1
}

OBJECT RomulanAlarmPanel		RomulanEnvironment
{
    string Description2		RomulanAlarmPanelDesc2
    string Description3		RomulanAlarmPanelDesc3
    string Description1		RomulanAlarmPanelDesc1
    string InteractiveType		Usable
    string RadarDescription		AlarmPanelRadar
}

OBJECT PulsePhaseInverter		FederationEnvironment
{
    string Description1		PulsePhaseInverterDesc1
    string Description2		PulsePhaseInverterDesc2
    string Description3		PulsePhaseInverterDesc3
    string InteractiveType		Usable
    string RadarDescription		PulsePhaseInverterRadar
}

OBJECT AttrexianSteamPanel		AttrexianEnvironment
{
    string Description2		AttrexianSteamPanelDesc2
    string Description3		AttrexianSteamPanelDesc3
    string InteractiveType		TricorderUsable
    string Description1		AttrexianSteamPanelDesc1
    string RadarDescription		AttrexianSteamPanelRadar
}

OBJECT AttrexianShutterPanel		AttrexianEnvironment
{
    string Description1		AttrexianShutterPanelDesc1
    string Description2		AttrexianShutterPanelDesc2
    string Description3		AttrexianShutterPanelDesc3
    string InteractiveType		Usable
    string RadarDescription		AttrexianShutterPanelRadar
}

OBJECT TransportOutLurker		DisplayEffects
{
    string AnimName		transport_out
    string EffectPosName		"Bip01 Spine1"
    float EffectTime		3
    string ShaderName		fadeout-lurker
    float SoundName		1
    float TransportTime		2
    string EffectName		fx/fx-fadeeffect-lurker.tik
    float Immobilize		1
    float AttachEffect		0
    float HideFeatures		0
}

OBJECT TransportOutChewer		DisplayEffects
{
    string AnimName		transport_out
    string EffectName		fx/fx-fadeeffect-chewer.tik
    string EffectPosName		"Bip01 Spine1"
    float EffectTime		3
    string ShaderName		fadeout-chewer
    float TransportTime		2
    float SoundName		1
    float Immobilize		1
    float AttachEffect		0
    float HideFeatures		0
}

OBJECT TransportOutQuad		DisplayEffects
{
    string AnimName		transport_out
    string EffectName		fx/fx-fadeeffect-quad.tik
    string EffectPosName		"Bip01 Spine1"
    float EffectTime		4
    string ShaderName		fadeout-quad
    float SoundName		1
    float TransportTime		2
    float Immobilize		1
    float AttachEffect		0
    float HideFeatures		0
}

OBJECT TransportOutBasher		DisplayEffects
{
    string AnimName		transport_out
    string EffectName		fx/fx-fadeeffect-basher.tik
    string EffectPosName		"Bip01 Spine1"
    float EffectTime		4
    string ShaderName		fadeout-basher
    float SoundName		1
    float TransportTime		2
    float Immobilize		1
    float AttachEffect		0
    float HideFeatures		0
}

OBJECT KlingonLiftPanel		KlingonEnvironment
{
    string Description1		KlingonLiftPanelDesc1
    string Description2		KlingonLiftPanelDesc2
    string Description3		KlingonLiftPanelDesc3
    string InteractiveType		Usable
    string RadarDescription		KlingonLiftPanelRadar
}

OBJECT TrainingCrystalFormation		FederationEnvironment
{
    string Description2		TrainingCrystalFormationDesc2
    string Description3		TrainingCrystalFormationDesc3
    string InteractiveType		NonInteractiveNoReticule
    string RadarDescription		CrystalRadar
    string Description1		TrainingCrystalFormationDesc1
}

OBJECT TrainingPanel		FederationEnvironment
{
    string Description2		TrainingPanelDesc2
    string Description3		TrainingPanelDesc3
    string Description1		TrainingPanelDesc1
    string InteractiveType		Usable
    string RadarDescription		TrainingPanelRadar
}

OBJECT ShuttleBayLift		FederationEnvironment
{
    string Description1		ShuttleBayLiftDesc1
    string Description2		ShuttleBayLiftDesc2
    string Description3		ShuttleBayLiftDesc3
    string InteractiveType		Usable
}

OBJECT ShuttleComputerPanel		FederationEnvironment
{
    string Description1		ShuttleComputerPanelDesc1
    string Description2		ShuttleComputerPanelDesc2
    string Description3		ShuttleComputerPanelDesc3
    string InteractiveType		TricorderUsable
}

OBJECT RomulanSniperTower		RomulanEnvironment
{
    string Description1		RomulanSniperTowerDesc1
    string Description2		RomulanSniperTowerDesc2
    string Description3		RomulanSniperTowerDesc3
    string InteractiveType		Destructable
}

OBJECT ShuttleBayDoors		FederationEnvironment
{
    string Description1		ShuttleBayDoorsDesc1
    string Description2		ShuttleBayDoorsDesc2
    string Description3		ShuttleBayDoorsDesc3
    string InteractiveType		Usable
    string RadarDescription		ShuttleBayDoorsRadar
}

OBJECT RomulanBossMachinery		RomulanEnvironment
{
    string Description1		RomulanBossMachineryDesc1
    string Description2		RomulanBossMachineryDesc2
    string Description3		RomulanBossMachineryDesc3
    string InteractiveType		Destructable
}

OBJECT TrainingElevatorSwitch		FederationEnvironment
{
    string Description2		TrainingElevatorSwitchDesc2
    string Description3		TrainingElevatorSwitchDesc3
    string Description1		TrainingElevatorSwitchDesc1
    string InteractiveType		Usable
    string RadarDescription		TrainingElevatorRadar
}

OBJECT TrainingPowerPanel		FederationEnvironment
{
    string Description1		TrainingPowerPanelDesc1
    string Description2		TrainingPowerPanelDesc2
    string Description3		TrainingPowerPanelDesc3
    string InteractiveType		Usable
    string RadarDescription		TrainingPowerPanelRadar
}

OBJECT BugPlant		IdryllEnvironment
{
    string Description2		BugPlantDesc2
    string Description3		BugPlantDesc3
    string InteractiveType		NonInteractive
}

OBJECT IdryllExplodableCrate		IdryllEnvironment
{
    string Description1		IdryllExplodableCrateDesc1
    string Description2		IdryllExplodableCrateDesc2
    string Description3		IdryllExplodableCrateDesc3
    string InteractiveType		Destructable
    string RadarDescription		IdryllExplodableCrateRadar
}

OBJECT ExplodableCrate		AttrexianEnvironment
{
    string Description1		ExplodableCrateDesc1
    string Description2		ExplodableCrateDesc2
    string Description3		ExplodableCrateDesc3
    string InteractiveType		Destructable
    string RadarDescription		ExplodableCrateRadar
}

OBJECT KorbanDoorPanel		KlingonEnvironment
{
    float Description1		1
    string Description2		KorbanDoorPanelDesc2
    string Description3		KorbanDoorPanelDesc3
    string InteractiveType		NonInteractive
}

OBJECT BrokenPhaseConverter		FederationEnvironment
{
    float Description1		1
    string Description2		BrokenPhaseConverterDesc2
    string Description3		BrokenPhaseConverterDesc3
    string InteractiveType		NonInteractive
}

OBJECT RomGuardMaleGood		Humanoids
{
    string Description2		RomGuardMaleGoodDesc2
    string Description3		RomGuardMaleGoodDesc3
    string InteractiveType		Friendly
    float PainChance		1
    string RadarDescription		RomulanInstallationGuardMaleRadar
    float fov		110
    float health		40
    float visiondistance		512
}

OBJECT RomGuardFemaleGood		Humanoids
{
    string Description2		RomGuardFemaleGoodDesc2
    string Description3		RomGuardFemaleGoodDesc3
    string InteractiveType		Friendly
    float fov		110
    float health		40
    float visiondistance		512
    string RadarDescription		RomulanInstallationGuardFemaleRadar
}

OBJECT RomulanCommEquipment		RomulanEnvironment
{
    string Description1		RomulanCommEquipmentDesc1
    string Description2		RomulanCommEquipmentDesc2
    string Description3		RomulanCommEquipmentDesc3
    string InteractiveType		Destructable
    string RadarDescription		CommEquipmentRadar
}

OBJECT Waypoint		GlobalEnvironments
{
    string InteractiveType		Location
}

OBJECT RomulanVent		RomulanEnvironment
{
    string InteractiveType		Usable
    string Description3		RomulanVentDesc3
    string Description2		RomulanVentDesc2
    string Description1		RomulanVentDesc1
}

OBJECT AttrexianFemaleTeammate		Humanoids
{
    string Description2		AttrexianM7PistolDesc2
    string Description3		AttrexianM7PistolDesc3
    string InteractiveType		Teammate
    string RadarDescription		AttrexianRadar
    float Description1		1
}

OBJECT AttrexianMaleTeammate		Humanoids
{
    string Description2		AttrexianMaleTeammateDesc2
    string Description3		AttrexianMaleTeammateDesc3
    string InteractiveType		Teammate
    string RadarDescription		AttrexianMaleTeammateRadar
}

OBJECT TrilithiumResin		KlingonEnvironment
{
    string Description1		TrilithiumResinDesc1
    string Description2		TrilithiumResinDesc2
    string Description3		TrilithiumResinDesc3
    string InteractiveType		Destructable
    string RadarDescription		TrilithiumResinRadar
}

OBJECT MaintenancePanel		KlingonEnvironment
{
    string Description1		MaintenancePanelDesc1
    string Description2		MaintenancePanelDesc2
    string Description3		MaintenancePanelDesc3
    string InteractiveType		Usable
}

OBJECT AndorianMaleGood		Humanoids
{
    string Description2		AndorianMaleGoodDesc2
    string Description3		AndorianMaleGoodDesc3
    string InteractiveType		Friendly
}

OBJECT KlingonMaleMercGood		Humanoids
{
    string Description2		KlingonMaleMercGoodDesc2
    string Description3		KlingonMaleMercGoodDesc3
    string InteractiveType		Friendly
}

OBJECT KlingonFemaleMercGood		Humanoids
{
    string Description2		KlingonFemaleMercGoodDesc2
    string Description3		KlingonFemaleMercGoodDesc3
    string InteractiveType		Friendly
}

OBJECT HumanMaleMercGood		Humanoids
{
    string Description2		HumanMaleMercGoodDesc2
    string Description3		HumanMaleMercGoodDesc3
    string InteractiveType		Friendly
}

OBJECT HumanFemaleMercGood		Humanoids
{
    string Description2		HumanFemaleMercGoodDesc2
    string Description3		HumanFemaleMercGoodDesc3
    string InteractiveType		Friendly
}

OBJECT TurboLiftRepairPanel		FederationEnvironment
{
    string Description1		TurboLiftRepairPanelDesc1
    string Description2		TurboLiftRepairPanelDesc2
    string Description3		TurboLiftRepairPanelDesc3
    string InteractiveType		Usable
}

OBJECT Belt		FederationEnvironment
{
    float Description1		1
    string Description2		BeltDesc2
    string Description3		BeltDesc3
}

OBJECT BootsSloppy		FederationEnvironment
{
    string Description2		BootsSloppyDesc2
    string Description3		BootsSloppyDesc3
}

OBJECT PantsFolded		FederationEnvironment
{
    string Description2		PantsFoldedDesc2
    string Description3		PantsFoldedDesc3
}

OBJECT PantsHung		FederationEnvironment
{
    string Description2		PantsHungDesc2
    string Description3		PantsHungDesc3
}

OBJECT ShirtFolded		FederationEnvironment
{
    string Description2		ShirtFoldedDesc2
    string Description3		ShirtFoldedDesc3
}

OBJECT ShirtHung		FederationEnvironment
{
    string Description2		ShirtHungDesc2
    string Description3		ShirtHungDesc3
}

OBJECT WristGear		FederationEnvironment
{
    string Description2		WristGearDesc2
    string Description3		WristGearDesc3
}

OBJECT TransportOutFederationWeapons		DisplayEffects
{
    float EffectTime		0.3
    string ShaderName		transport
    float TransportTime		0.3
    float Immobilize		1
    float AttachEffect		0
    float HideFeatures		0
}

OBJECT TransportInFederationWeapons		DisplayEffects
{
    float EffectTime		0.3
    string ShaderName		transport
    float TransportTime		0.3
    float Immobilize		1
    float AttachEffect		0
    float HideFeatures		0
}

OBJECT RomulanExplosiveCrate		RomulanEnvironment
{
    string Description2		RomulanExplosiveCrateDesc2
    string Description3		RomulanExplosiveCrateDesc3
    string InteractiveType		Destructable
    string Description1		RomulanExplosiveCrateDesc1
}

OBJECT OmagGood		NPC
{
    string Description2		OmagGoodDesc2
    string Description3		OmagGoodDesc3
    string InteractiveType		Friendly
    string RadarDescription		OmagRadar
    string Description1		OmagGoodDesc1
}

OBJECT PhotonControls		FederationEnvironment
{
    string Description1		PhotonControlsDesc1
    string Description2		PhotonControlsDesc2
    string Description3		PhotonControlsDesc3
    string InteractiveType		TricorderUsable
}

OBJECT EnterpriseHatch		FederationEnvironment
{
    string Description1		EnterpriseHatchDesc1
    string Description2		EnterpriseHatchDesc2
    string Description3		EnterpriseHatchDesc3
    string InteractiveType		Usable
}

OBJECT DallasForcefieldControl		DallasEnvironment
{
    string Description1		DallasForcefieldControlDesc1
    string Description2		DallasForcefieldControlDesc2
    string Description3		DallasForcefieldControlDesc3
    string InteractiveType		Usable
    string RadarDescription		ForcefieldControlRadar
}

OBJECT GravityControls		DallasEnvironment
{
    string Description1		GravityControlsDesc1
    string Description2		GravityControlsDesc2
    string Description3		GravityControlsDesc3
    string InteractiveType		TricorderUsable
    string RadarDescription		GravityControlsRadar
}

OBJECT ManualDoorRelease		DallasEnvironment
{
    string Description1		ManualDoorReleaseDesc1
    string Description2		ManualDoorReleaseDesc2
    string Description3		ManualDoorReleaseDesc3
    string InteractiveType		Usable
    string RadarDescription		ManualDoorRadar
}

OBJECT ShuttleDoorControl		DallasEnvironment
{
    string Description1		ShuttleDoorControlDesc1
    string Description2		ShuttleDoorControlDesc2
    string Description3		ShuttleDoorControlDesc3
    string InteractiveType		TricorderUsable
    string RadarDescription		ShuttleDoorControlsRadar
}

OBJECT EngineeringControls		DallasEnvironment
{
    string Description1		EngineeringControlsDesc1
    string Description2		EngineeringControlsDesc2
    string Description3		EngineeringControlsDesc3
    string InteractiveType		TricorderUsable
    string RadarDescription		EngineeringControlsRadar
}

OBJECT CargoDoorControl		DallasEnvironment
{
    string Description1		CargoDoorControlDesc1
    string Description2		CargoDoorControlDesc2
    string Description3		CargoDoorControlDesc3
    string InteractiveType		TricorderUsable
    string RadarDescription		CargoDoorControlsRadar
}

OBJECT TurboLiftControls		DallasEnvironment
{
    string Description1		TurboLiftControlsDesc1
    string Description2		TurboLiftControlsDesc2
    string Description3		TurboLiftControlsDesc3
    string InteractiveType		Usable
    string RadarDescription		TurboLiftControlsRadar
}

OBJECT EnterpriseEnergyTerminal		FederationEnvironment
{
    string Description1		EnterpriseEnergyTerminalDesc1
    string Description2		EnterpriseEnergyTerminalDesc2
    string Description3		EnterpriseEnergyTerminalDesc3
    string InteractiveType		Usable
    string RadarDescription		EnergyTerminalRadar
}

OBJECT EnterpriseHealthTerminal		FederationEnvironment
{
    string Description1		EnterpriseHealthTerminalDesc1
    string Description2		EnterpriseHealthTerminalDesc3
    string Description3		EnterpriseHealthTerminalDesc3
    string InteractiveType		Usable
    string RadarDescription		HealthTerminalRadar
}

OBJECT TurboLiftControlGrid		DallasEnvironment
{
    string Description1		TurboLiftControlGridDesc1
    string Description2		TurboLiftControlGridDesc2
    string Description3		TurboLiftControlGridDesc3
    string InteractiveType		TricorderUsable
    string RadarDescription		TurboLiftControlGridRadar
}

OBJECT HoldInfoRifle		Animations
{
    string Aim		romsniperrifle_aim
    float AimTimeMax		0.45
    float AimTimeMin		0.25
    string CombatBackpedal		swat_backpedal
    string CombatGunIdle		romsniperrifle_tense_idle
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		swat_calm_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string Draw		romsniperrifle_draw
    string Fire		romsniperrifle_fire
    float FireTimeMax		-1
    float FireTimeMin		-1
    string Idle		romsniperrifle_calm_idle
    string IdleBackpedal		backpedal
    string IdleGunIdle		romsniperrifle_calm_idle
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    float InitialSpreadX		3000
    float InitialSpreadY		3000
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    string Melee		romsniperrifle_melee
    string PostFire		romsniperrifle_postfire
    string PreFire		romsniperrifle_prefire
    string PutAway		romsniperrifle_putaway
    float SpreadMultiplier		0.85
    float spreadx		50
    float spready		50
}

OBJECT IdryllRebelEliteMale		IdryllRebel
{
    string Description1		IdryllRebelDesc1
    string Description2		IdryllRebelDesc2
    string Description3		IdryllRebelDesc3
    string InteractiveType		Enemy
    float PainChance		1
    string RadarDescription		IdryllRebelRadar
    float fov		120
    float health		40
    float playerhatemodifier		2.5
    float visiondistance		3600
}

OBJECT IdryllRebelHumanoidMale		Humanoids
{
    string Description2		IdryllRebelMaleDesc2
    string Description3		IdryllRebelMaleDesc3
    string InteractiveType		Enemy
}

OBJECT IdryllRebelHumanoidFemale		Humanoids
{
    string Description2		IdryllRebelFemaleDesc2
    string Description3		IdryllRebelFemaleDesc3
    string InteractiveType		Enemy
}

OBJECT KlingonFireVentControl		KlingonEnvironment
{
    string Description1		KlingonFireVentControlDesc1
    string Description2		KlingonFireVentControlDesc2
    string Description3		KlingonFireVentControlDesc3
    string InteractiveType		Usable
    string RadarDescription		FireVentRadar
}

OBJECT KlingonCraneManualOverride		KlingonEnvironment
{
    string Description1		KlingonCraneManualOverrideDesc1
    string Description2		KlingonCraneManualOverrideDesc2
    string Description3		KlingonCraneManualOverrideDesc3
    string InteractiveType		Usable
    string RadarDescription		CraneOverrideRadar
}

OBJECT RomulanCommEquipmentDamaged		RomulanEnvironment
{
    string Description2		RomulanCommEquipmentDamagedDesc2
    string Description3		RomulanCommEquipmentDamagedDesc3
    string InteractiveType		NonInteractive
    string Description1		RomulanCommEquipmentDamagedDesc1
    string RadarDescription		CommEquipmentRadar
}

OBJECT FadeOutSniper		DisplayEffects
{
    string EffectName		fx/fx-fadeout-sniper.tik
    string EffectPosName		randombone
    float EffectTime		1.5
    float FadeTime		2
    float NumEffects		14
    string ShaderName		sniper_death
    string SoundName		snd_phaserdeath
    float Immobilize		1
    float AttachEffect		1
    float HideFeatures		0
}

OBJECT HoldAttrexianPistol		Animations
{
    string Aim		attrexpistol_aim
    float AimTimeMax		0.3
    float AimTimeMin		0.25
    string CombatBackpedal		swat_backpedal
    string CombatGunIdle		attrexpistol_tense_idle
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		swat_calm_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string Draw		attrexpistol_draw
    string Fire		attrexpistol_fire
    float FireTimeMax		1.25
    float FireTimeMin		1
    string Idle		attrexpistol_idle
    string IdleBackpedal		backpedal
    string IdleGunIdle		attrexpistol_calm_idle
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    string Melee		attrexpistol_melee
    string PostFire		attrexpistol_postfire
    string PreFire		attrexpistol_prefire
    string PutAway		attrexpistol_putaway
    float spreadx		10
    float spready		10
    float ShotCount		3
}

OBJECT HoldAttrexianSecurityPistol		Animations
{
    string Aim		attrexsecpistol_aim
    float AimTimeMax		0.3
    float AimTimeMin		0.25
    string CombatBackpedal		swat_backpedal
    string CombatGunIdle		attrexsecpistol_tense_idle
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		swat_calm_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string Draw		attrexsecpistol_draw
    string Fire		attrexsecpistol_fire
    float FireTimeMax		1.25
    float FireTimeMin		1
    string Idle		attrexsecpistol_idle
    string IdleBackpedal		backpedal
    string IdleGunIdle		attrexsecpistol_calm_idle
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    string Melee		attrexsecpistol_melee
    string PostFire		attrexsecpistol_postfire
    string PreFire		attrexsecpistol_prefire
    string PutAway		attrexsecpistol_putaway
    float spreadx		10
    float spready		10
    float ShotCount		3
}

OBJECT HoldMercPistol		Animations
{
    string Aim		mercpistol_aim
    float AimTimeMax		0.3
    float AimTimeMin		0.25
    string CombatBackpedal		swat_backpedal
    string CombatGunIdle		mercpistol_tense_idle
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		swat_calm_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string Draw		mercpistol_draw
    string Fire		mercpistol_fire
    float FireTimeMax		-1
    float FireTimeMin		-1
    string Idle		mercpistol_idle
    string IdleBackpedal		backpedal
    string IdleGunIdle		mercpistol_calm_idle
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    string Melee		mercpistol_melee
    string PostFire		mercpistol_postfire
    string PreFire		mercpistol_prefire
    string PutAway		mercpistol_putaway
    float spreadx		100
    float spready		100
    float ShotCount		3
}

OBJECT HoldMercShotgun		Animations
{
    string Aim		mercshotgun_aim
    float AimTimeMax		0.3
    float AimTimeMin		0.25
    string CombatBackpedal		swat_backpedal
    string CombatGunIdle		mercshotgun_tense_idle
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		swat_calm_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string Draw		mercshotgun_draw
    string Fire		mercshotgun_fire
    float FireTimeMax		1.25
    float FireTimeMin		1
    string Idle		mercshotgun_idle
    string IdleBackpedal		backpedal
    string IdleGunIdle		mercshotgun_calm_idle
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    string Melee		mercshotgun_melee
    string PostFire		mercshotgun_postfire
    string PreFire		mercshotgun_prefire
    string PutAway		mercshotgun_putaway
    float spreadx		300
    float spready		300
}

OBJECT HoldRomulanDisruptor		Animations
{
    string Aim		romdisruptor_aim
    float AimTimeMax		0.3
    float AimTimeMin		0.25
    string CombatBackpedal		swat_backpedal
    string CombatGunIdle		romdisruptor_tense_idle
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		swat_calm_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string Draw		romdisruptor_draw
    string Fire		romdisruptor_fire
    float FireTimeMax		1.25
    float FireTimeMin		1
    string Idle		romdisruptor_idle
    string IdleBackpedal		backpedal
    string IdleGunIdle		romdisruptor_calm_idle
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    string Melee		romdisruptor_melee
    string PostFire		romdisruptor_postfire
    string PreFire		romdisruptor_prefire
    string PutAway		romdisruptor_putaway
    float spreadx		10
    float spready		10
    float ShotCount		5
}

OBJECT HoldCompRifleEnhanced		Animations
{
    string Aim		compressionrifleenhanced_aim
    float AimTimeMax		0.3
    float AimTimeMin		0.25
    string CombatBackpedal		swat_backpedal
    string CombatGunIdle		compressionrifleenhanced_tense_idle
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		swat_calm_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string Draw		compressionrifleenhanced_draw
    string Fire		compressionrifleenhanced_fire
    float FireTimeMax		1.25
    float FireTimeMin		1
    string Idle		compressionrifleenhanced_idle
    string IdleBackpedal		backpedal
    string IdleGunIdle		compressionrifleenhanced_idle
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    string Melee		compressionrifleenhanced_melee
    string PostFire		compressionrifleenhanced_postfire
    string PreFire		compressionrifleenhanced_prefire
    string PutAway		compressionrifleenhanced_putaway
    float spreadx		10
    float spready		10
    float ShotCount		5
    string CombatGunTwitch		weapon-twitch
    string IdleGunTwitch		weapon-twitch
}

OBJECT IdryllRebelMortarMale		IdryllRebel
{
    OBJECT PainChance		DamageType
    {
        float comp_rifle		0.85
        float disruptor		0.85
        float electric		0.45
    }

    string Description1		IdryllRebelDesc1
    string Description2		IdryllRebelDesc2
    string Description3		IdryllRebelDesc3
    string InteractiveType		Enemy
    float PainChance		1
    string RadarDescription		IdryllRebelRadar
    float fov		160
    float health		40
    float playerhatemodifier		2.5
    float visiondistance		5000
}

OBJECT HoldIdryllRebelGauntletWithShield		Animations
{
    string Aim		gauntlet_ffshield_idle
    float AimTimeMax		-1
    float AimTimeMin		-1
    string CombatBackpedal		swat_backpedal
    string CombatGunIdle		defensive_hold
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		swat_calm_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string Draw		gauntlet_ffshield_draw
    string Fire		gauntlet_ffshield_fire
    float FireTimeMax		-1
    float FireTimeMin		-1
    string Idle		gauntlet_ffshield_idle
    string IdleBackpedal		backpedal
    string IdleGunIdle		idle
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    float InitialSpreadX		1
    float InitialSpreadY		1
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    string Melee		melee_noshield-combo
    string PostFire		gauntlet_ffshield_postfire
    string PreFire		gauntlet_ffshield_prefire
    string PutAway		gauntlet_ffshield_putaway
    float SpreadMultiplier		1
    float spreadx		200
    float spready		200
}

OBJECT IdryllRebelMaleShield		IdryllRebel
{
    OBJECT PainChance		DamageType
    {
    }

    string Description1		IdryllRebelDesc1
    string Description2		IdryllRebelDesc2
    string Description3		IdryllRebelDesc3
    string InteractiveType		Enemy
    float PainChance		1
    string RadarDescription		IdryllRebelRadar
    float fov		160
    float health		75
    float playerhatemodifier		2.5
    float visiondistance		3600
}

OBJECT IdryllEliteMaleShield		IdryllRebel
{
    OBJECT PainChance		DamageType
    {
    }

    string Description1		IdryllRebelDesc1
    string Description2		IdryllRebelDesc2
    string Description3		IdryllRebelDesc3
    string InteractiveType		Enemy
    float PainChance		1
    string RadarDescription		IdryllRebelRadar
    float fov		160
    float health		75
    float playerhatemodifier		2.5
    float visiondistance		3600
}

OBJECT RomulanRebelM11Pistol		Humanoids
{
    OBJECT PainChance		DamageType
    {
        float comp_rifle		0.85
        float disruptor		0.85
        float electric		0.45
        float gas		0.02
    }

    string Description1		RomRebelM11PistolDesc1
    string Description2		RomRebelM11PistolDesc2
    string Description3		RomRebelM11PistolDesc3
    string InteractiveType		Enemy
    float PainChance		1
    string RadarDescription		RomRebelM11RadarDesc
    float fov		120
    float health		75
    float playerhatemodifier		1.5
    float visiondistance		1200
}

OBJECT KlingonMercBatlethMale		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    string InteractiveType		Enemy
    string Description3		KlingonMercBatlethMaleDesc3
    string Description2		KlingonMercBatlethMaleDesc2
    float Description1		1
    float PainChance		1
    float RadarDescription		1
    float fov		120
    float health		80
    float playerhatemodifier		1.5
    float visiondistance		1200
}

OBJECT KlingonMercBatlethFemale		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    string InteractiveType		Enemy
    string Description3		KlingonMercBatlethFemaleDesc3
    string Description2		KlingonMercBatlethFemaleDesc2
    float Description1		1
    float PainChance		1
    float RadarDescription		1
    float fov		120
    float health		80
    float playerhatemodifier		1.5
    float visiondistance		1200
}

OBJECT KlingonMercKnifeMale		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    string InteractiveType		Enemy
    string Description3		KlingonMercKnifeMaleDesc3
    string Description2		KlingonMercKnifeMaleDesc2
    float Description1		1
    float PainChance		1
    float RadarDescription		1
    float fov		120
    float health		80
    float playerhatemodifier		1.5
    float visiondistance		1200
}

OBJECT KlingonMercKnifeFemale		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    string InteractiveType		Enemy
    string Description3		KlingonMercKnifeFemaleDesc3
    string Description2		KlingonMercKnifeFemaleDesc2
    float Description1		1
    float PainChance		1
    float RadarDescription		1
    float fov		120
    float health		80
    float playerhatemodifier		1.5
    float visiondistance		1200
}

OBJECT KlingonMercDisruptorMale		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    string InteractiveType		Enemy
    string Description3		KlingonMercDisruptorMaleDesc3
    string Description2		KlingonMercDisruptorMaleDesc2
    float Description1		1
    float PainChance		1
    float RadarDescription		1
    float fov		120
    float health		80
    float playerhatemodifier		1.5
    float visiondistance		1200
}

OBJECT KlingonMercDisruptorFemale		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    string InteractiveType		Enemy
    string Description3		KlingonMercDisruptorFemaleDesc3
    string Description2		KlingonMercDisruptorFemaleDesc2
    float Description1		1
    float PainChance		1
    float RadarDescription		1
    float fov		120
    float health		80
    float playerhatemodifier		1.5
    float visiondistance		1200
}

OBJECT RomulanRebelM11Rifle		Humanoids
{
    OBJECT PainChance		DamageType
    {
        float gas		0.02
    }

    float Description1		1
    string Description2		RomulanRebelM11RifleDesc2
    string Description3		RomulanRebelM11RifleDesc3
    string InteractiveType		Enemy
    float PainChance		1
    float RadarDescription		1
    float fov		120
    float health		70
    float playerhatemodifier		1.5
    float visiondistance		1200
}

OBJECT RomulanRebelM11Photon		Humanoids
{
    OBJECT PainChance		DamageType
    {
        float gas		0.02
    }

    float Description1		1
    string Description2		RomulanRebelM11PhotonDesc2
    string Description3		RomulanRebelM11PhotonDesc3
    string InteractiveType		Enemy
    float PainChance		1
    float RadarDescription		1
    float fov		120
    float playerhatemodifier		1.5
    float visiondistance		1200
    float health		150
}

OBJECT RomulanRebelM11Grenade		Humanoids
{
    OBJECT PainChance		DamageType
    {
        float gas		0.02
    }

    float Description1		1
    string Description2		RomulanRebelM11GrenadeDesc2
    string Description3		RomulanRebelM11GrenadeDesc3
    string InteractiveType		Enemy
    float PainChance		1
    float RadarDescription		1
    float fov		360
    float health		100
    float playerhatemodifier		1.5
    float visiondistance		3000
}

OBJECT HoldRomulanHandgrenade		Animations
{
    string Aim		grenade_idle
    float AimTimeMax		1
    float AimTimeMin		1
    string CombatBackpedal		swat_backpedal
    string CombatGunIdle		grenade_idle
    string Draw		grenade_idle
    string Fire		grenade_idle
    string Idle		grenade_idle
    string IdleGunIdle		grenade_idle
    string Melee		grenade_idle
    string PostFire		grenade_idle
    string PreFire		grenade_idle
    string PutAway		grenade_idle
    float spreadx		1
    float spready		1
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		swat_calm_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    float FireTimeMax		1
    float FireTimeMin		1
    string IdleBackpedal		backpedal
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    float IdleRStrafe		1
    string IdleRun		run
    string IdleWalk		walk
    float MaxTorsoPitch		1
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
}

OBJECT RomulanRebelM2Pistol		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    string Description2		RomulanRebelM2PistolDesc2
    string Description3		RomulanRebelM2PistolDesc3
    string InteractiveType		Enemy
    float PainChance		1
    string RadarDescription		RomulanRebelM2PistolRadar
    float fov		120
    float health		40
    float playerhatemodifier		1.5
    float visiondistance		1200
}

OBJECT RomulanRebelM2Rifle		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    string Description2		RomulanRebelM2RifleDesc2
    string Description3		RomulanRebelM2RifleDesc3
    string InteractiveType		Enemy
    float PainChance		1
    string RadarDescription		RomulanRebelM2RifleRadar
    float fov		120
    float health		50
    float playerhatemodifier		1.5
    float visiondistance		1200
}

OBJECT IdryllRebelMortarFemale		IdryllRebel
{
    OBJECT PainChance		DamageType
    {
    }

    string Description1		IdryllRebelDesc1
    string Description2		IdryllRebelDesc2
    string Description3		IdryllRebelDesc3
    string InteractiveType		Enemy
    float PainChance		1
    string RadarDescription		IdryllRebelRadar
    float fov		160
    float health		40
    float playerhatemodifier		2.5
}

OBJECT IdryllRebelFemaleShield		IdryllRebel
{
    OBJECT PainChance		DamageType
    {
    }

    string Description1		IdryllRebelDesc1
    string Description2		IdryllRebelDesc2
    string Description3		IdryllRebelDesc3
    string InteractiveType		Enemy
    float PainChance		1
    string RadarDescription		IdryllRebelRadar
    float fov		160
    float health		75
    float playerhatemodifier		2.5
}

OBJECT IdryllEliteFemaleShield		IdryllRebel
{
    OBJECT PainChance		DamageType
    {
    }

    string Description1		IdryllRebelDesc1
    string Description2		IdryllRebelDesc2
    string Description3		IdryllRebelDesc3
    string InteractiveType		Enemy
    float PainChance		1
    string RadarDescription		IdryllRebelRadar
    float fov		160
    float health		75
    float playerhatemodifier		2.5
}

OBJECT RomulanRebelM11Sniper		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    string Description2		RomulanRebelM11SniperDesc2
    string Description3		RomulanRebelM11SniperDesc3
    string InteractiveType		Enemy
    float PainChance		1
    float RadarDescription		1
    float fov		270
    float health		100
    float playerhatemodifier		1.5
    float visiondistance		3600
}

OBJECT RomulanSoldierM10Rifle		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    string Description2		RomulanSoldierM10RifleDesc2
    string Description3		RomulanSoldierM10RifleDesc3
    string InteractiveType		Enemy
    float PainChance		1
    string RadarDescription		RomulanSoldierRadar
    float fov		75
    float health		25
    float playerhatemodifier		1.5
    float visiondistance		2048
}

OBJECT RomulanSoldierM10Pistol		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    string Description2		RomulanSoldierM10PistolDesc2
    string Description3		RomulanSoldierM10PistolDesc3
    string InteractiveType		Enemy
    float PainChance		1
    string RadarDescription		RomulanSoldierRadar
    float fov		75
    float health		25
    float playerhatemodifier		1.5
    float visiondistance		2048
}

OBJECT RomulanSnowGuardM10Rifle		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    string Description2		RomulanSnowGuardM10RifleDesc2
    string Description3		RomulanSnowGuardM10RifleDesc3
    string InteractiveType		Enemy
    float PainChance		1
    string RadarDescription		RomulanSoldierRadar
    float fov		120
    float health		25
    float playerhatemodifier		1.5
    float visiondistance		1200
}

OBJECT RomulanInstGuardM10Pistol		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    string Description2		RomulanInstGuardM10PistolDesc2
    string Description3		RomulanInstGuardM10PistolDesc3
    string InteractiveType		Enemy
    float PainChance		1
    string RadarDescription		RomulanSoldierRadar
    float fov		120
    float health		25
    float playerhatemodifier		1.5
    float visiondistance		1200
}

OBJECT RomulanCommanderM10Pistol		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    string Description1		RomulanCommanderM10PistolDesc1
    string Description2		RomulanCommanderM10PistolDesc2
    string Description3		RomulanCommanderM10PistolDesc3
    string InteractiveType		Enemy
    float PainChance		1
    string RadarDescription		RomulanCommanderRadar
    float fov		120
    float health		25
    float playerhatemodifier		1.5
    float visiondistance		1200
}

OBJECT AttrexianM4NoWeapon		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    string Description2		AttrexianM4NoWeaponDesc2
    string Description3		AttrexianM4NoWeaponDesc3
    string InteractiveType		Friendly
    float PainChance		1
    string RadarDescription		Attrexian1Radar
    float fov		120
    float health		50
    float playerhatemodifier		1.5
    float visiondistance		1200
}

OBJECT AttrexianM4Pistol		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    string Description2		AttrexianM4PistolDesc2
    string Description3		AttrexianM4PistolDesc3
    string InteractiveType		Friendly
    float PainChance		1
    string RadarDescription		Attrexian2Radar
    float fov		120
    float health		50
    float playerhatemodifier		1.5
    float visiondistance		1200
}

OBJECT AttrexianM4Rifle		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    string Description2		AttrexianM4RifleDesc2
    string Description3		AttrexianM4RifleDesc3
    string InteractiveType		Friendly
    float PainChance		1
    string RadarDescription		Attrexian3Radar
    float fov		120
    float health		50
    float playerhatemodifier		1.5
    float visiondistance		1200
}

OBJECT AttrexianM4SecurityPistol		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    string Description2		AttrexianM4SecurityPistolDesc2
    string Description3		AttrexianM4SecurityPistolDesc3
    string InteractiveType		Friendly
    float PainChance		1
    string RadarDescription		Attrexian4Radar
    float fov		120
    float health		50
    float playerhatemodifier		1.5
    float visiondistance		1200
}

OBJECT AttrexianM7NoWeapon		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    string Description2		AttrexianM7NoWeaponDesc2
    string Description3		AttrexianM7NoWeaponDesc3
    string InteractiveType		Friendly
    float PainChance		1
    string RadarDescription		AttrexianRadar
    float fov		120
    float health		25
    float playerhatemodifier		1.5
    float visiondistance		1200
}

OBJECT AttrexianM7Pistol		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    string Description2		AttrexianM7PistolDesc2
    string Description3		AttrexianM7PistolDesc3
    string InteractiveType		Friendly
    float PainChance		1
    string RadarDescription		Attrexian6Radar
    float fov		120
    float health		25
    float playerhatemodifier		1.5
    float visiondistance		1200
}

OBJECT AttrexianM7Rifle		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    string Description2		AttrexianM7RifleDesc2
    string Description3		AttrexianM7RifleDesc3
    string InteractiveType		Friendly
    float PainChance		1
    string RadarDescription		Attrexian7Radar
    float fov		120
    float health		25
    float playerhatemodifier		1.5
    float visiondistance		1200
}

OBJECT AttrexianM7SecurityPistol		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    string Description2		AttrexianM7SecurityPistolDesc2
    string Description3		AttrexianM7SecurityPistolDesc3
    string InteractiveType		Friendly
    float PainChance		1
    string RadarDescription		Attrexian8Radar
    float fov		120
    float health		25
    float playerhatemodifier		1
    float visiondistance		1200
}

OBJECT TransportOutFederationAttach		DisplayEffects
{
    string EffectName		fx/fx-beamsparkle.tik
    string EffectPosName		"Bip01 Pelvis"
    float EffectTime		1.25
    string ShaderName		transport
    string SoundName		snd_bodytransportout
    float TransportTime		1.25
    float Immobilize		1
    float AttachEffect		0
    float HideFeatures		1
}

OBJECT Medic		Multiplayer
{
    string Description1		MedicDesc1
    string Description2		MedicDesc1
    string Description3		MedicDesc1
    string InteractiveType		Usable
}

OBJECT MODelectric		MOD
{
    string PainShaderName		electriclines
}

OBJECT MODdefault		MOD
{
    string PainShaderName		mod_default
    float DoPainSound		1
}

OBJECT HoldIdryllSaboteurGauntlet		Animations
{
    string Aim		gauntlet_ffshield_idle
    float AimTimeMax		-1
    float AimTimeMin		-1
    string CombatBackpedal		swat_backpedal
    string CombatGunIdle		defensive_hold
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		swat_calm_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string Draw		gauntlet_ffshield_draw
    string Fire		gauntlet_ffshield_fire
    float FireTimeMax		-1
    float FireTimeMin		-1
    string Idle		gauntlet_ffshield_idle
    string IdleBackpedal		backpedal
    string IdleGunIdle		idle
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    string PostFire		gauntlet_ffshield_postfire
    string PreFire		gauntlet_ffshield_prefire
    string PutAway		gauntlet_ffshield_putaway
    float spreadx		30
    float spready		30
    float InitialSpreadX		1
    float InitialSpreadY		1
    string Melee		gauntlet_shield_meleecombo
    float SpreadMultiplier		1
    float ShotCount		4
}

OBJECT IdryllM6SaboteurGauntlet		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    string Description2		IdryllRebelMaleDesc2
    string Description3		IdryllRebelMaleDesc3
    string InteractiveType		Enemy
    float fov		360
    float health		120
    float playerhatemodifier		1.5
    float visiondistance		2000
    float Description1		1
    string RadarDescription		IdryllRebel1Radar
}

OBJECT TransportOutMultiplayer		DisplayEffects
{
    string EffectName		fx/fx-beamsparkle.tik
    string EffectPosName		Bip01
    float EffectTime		1.25
    string ShaderName		transport
    string SoundName		snd_bodytransportout
    float TransportTime		1.25
    float Immobilize		0
    float AttachEffect		0
    float HideFeatures		1
}

OBJECT TransportInMultiplayer		DisplayEffects
{
    string EffectName		fx/fx-beamsparkle.tik
    string EffectPosName		Bip01
    float EffectTime		0.75
    float ShaderName		1
    string SoundName		snd_bodytransportin
    float TransportTime		0.75
    float Immobilize		0
    float AttachEffect		0
    float HideFeatures		1
}

OBJECT HoldKlingonBossTetryon		Animations
{
    string Aim		tetryon_aim
    float AimTimeMax		0.3
    float AimTimeMin		0.25
    string CombatBackpedal		swat_backpedal
    string CombatGunIdle		tetryon_tense_idle
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		swat_calm_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string Draw		tetryon_draw
    string Fire		tetryon_fire
    float FireTimeMax		2.5
    float FireTimeMin		2
    float Idle		1
    string IdleBackpedal		backpedal
    string IdleGunIdle		tetryon_calm_idle
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    string Melee		tetryon_melee1
    string PostFire		tetryon_postfire
    string PreFire		tetryon_prefire
    string PutAway		tetryon_putaway
    float spreadx		100
    float spready		100
    float ShotCount		50
}

OBJECT MODdeathQuad		MOD
{
    string PainShaderName		mod_default
    float DoPainSound		0
}

OBJECT MODon_fire		MOD
{
    string PainShaderName		mod_default
    float DoPainSound		0
}

OBJECT Technician		Multiplayer
{
    string InteractiveType		Usable
    string Description1		TechnicianDesc1
    string Description2		TechnicianDesc1
    string Description3		TechnicianDesc1
}

OBJECT Demolitionist		Multiplayer
{
    string InteractiveType		Usable
    string Description1		DemolitionistDesc1
    string Description2		DemolitionistDesc1
    string Description3		DemolitionistDesc1
}

OBJECT Sniper		Multiplayer
{
    string InteractiveType		Usable
    string Description1		SniperDesc1
    string Description2		SniperDesc1
    string Description3		SniperDesc1
}

OBJECT HeavyWeapons		Multiplayer
{
    string InteractiveType		Usable
    string Description1		HeavyWeaponsDesc1
    string Description2		HeavyWeaponsDesc1
    string Description3		HeavyWeaponsDesc1
}

OBJECT Infiltrator		Multiplayer
{
    string InteractiveType		Usable
    string Description1		InfiltratorDesc1
    string Description2		InfiltratorDesc1
    string Description3		InfiltratorDesc1
}

OBJECT BombPlaceRed		Multiplayer
{
    string Description1		BombPlaceRedDesc1
    string InteractiveType		TricorderUsable
    string Description2		BombPlaceRedDesc1
    float Description3		1
}

OBJECT BombPlaceBlue		Multiplayer
{
    string Description1		BombPlaceBlueDesc1
    string InteractiveType		TricorderUsable
    string Description2		BombPlaceBlueDesc1
    float Description3		1
}

OBJECT SingularityRed		Multiplayer
{
    string Description1		SingularityRedDesc1
    string InteractiveType		TricorderUsable
    string Description2		SingularityRedDesc1
    float Description3		1
}

OBJECT SingularityBlue		Multiplayer
{
    string Description1		SingularityBlueDesc1
    string InteractiveType		TricorderUsable
    string Description2		SingularityBlueDesc1
    float Description3		1
}

OBJECT IdryllExplodableCrate2		IdryllEnvironment
{
    string Description1		IdryllExplodableCrate2Desc1
    string Description2		IdryllExplodableCrate2Desc2
    string Description3		IdryllExplodableCrate2Desc3
    string InteractiveType		Destructable
    string RadarDescription		IdryllExplodableCrate2Radar
}

OBJECT IdryllExplodableCrate3		IdryllEnvironment
{
    string Description1		IdryllExplodableCrate3Desc1
    string Description2		IdryllExplodableCrate3Desc2
    string Description3		IdryllExplodableCrate3Desc3
    string InteractiveType		Destructable
    string RadarDescription		IdryllExplodableCrate3Radar
}

OBJECT HoldIdryllM6RebelRifleShield		Animations
{
    string Aim		gauntlet_ffshield_idle
    float AimTimeMax		-1
    float AimTimeMin		-1
    string CombatBackpedal		swat_backpedal
    string CombatGunIdle		shield_idle
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		shield_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string Draw		gauntlet_ffshield_draw
    string Fire		gauntlet_ffshield_fire
    float FireTimeMax		-1
    float FireTimeMin		-1
    string Idle		gauntlet_ffshield_idle
    string IdleBackpedal		backpedal
    string IdleGunIdle		shield_idle
    string IdleLStrafe		strafe_left
    string IdleLegIdle		shield_idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    float InitialSpreadX		1
    float InitialSpreadY		1
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    string Melee		gauntlet_shield_meleecombo
    string PostFire		gauntlet_ffshield_postfire
    string PreFire		gauntlet_ffshield_prefire
    string PutAway		gauntlet_ffshield_putaway
    float SpreadMultiplier		1
    float spreadx		150
    float spready		150
    float ShotCount		5
}

OBJECT HoldIdryllM6RebelPistolShield		Animations
{
    string Aim		gauntlet_ffshield_idle
    float AimTimeMax		-1
    float AimTimeMin		-1
    string CombatBackpedal		swat_backpedal
    string CombatGunIdle		shield_idle
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		shield_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string Draw		gauntlet_ffshield_draw
    string Fire		gauntlet_ffshield_fire
    float FireTimeMax		-1
    float FireTimeMin		-1
    string Idle		gauntlet_ffshield_idle
    string IdleBackpedal		backpedal
    string IdleGunIdle		shield_idle
    string IdleLStrafe		strafe_left
    string IdleLegIdle		shield_idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    float InitialSpreadX		1
    float InitialSpreadY		1
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    string Melee		gauntlet_shield_meleecombo
    string PostFire		gauntlet_ffshield_postfire
    string PreFire		gauntlet_ffshield_prefire
    string PutAway		gauntlet_ffshield_putaway
    float spreadx		170
    float spready		170
    float SpreadMultiplier		1
    float ShotCount		4
}

OBJECT HoldIdryllM6RebelRifle		Animations
{
    string Aim		gauntlet_ffnoshield_idle
    float AimTimeMax		-1
    float AimTimeMin		-1
    string CombatBackpedal		swat_backpedal
    string CombatGunIdle		give_order
    string CombatLStrafe		knife_strafeL
    string CombatLegIdle		idle_weapon_legs
    string CombatRStrafe		knife_strafeR
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string Draw		gauntlet_ffnoshield_draw
    string Fire		gauntlet_ffnoshield_fire
    float FireTimeMax		-1
    float FireTimeMin		-1
    string Idle		gauntlet_ffnoshield_idle
    string IdleBackpedal		backpedal
    string IdleGunIdle		shield_idle
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    float InitialSpreadX		1
    float InitialSpreadY		1
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    string Melee		melee_noshield-combo
    string PostFire		gauntlet_ffnoshield_postfire
    string PreFire		gauntlet_ffnoshield_prefire
    string PutAway		gauntlet_ffnoshield_putaway
    float SpreadMultiplier		1
    float spreadx		0
    float spready		0
    float ShotCount		3
}

OBJECT IdryllHealthTerminal		IdryllEnvironment
{
    string Description1		IdryllHealthTerminalDesc1
    string Description2		IdryllHealthTerminalDesc2
    string Description3		IdryllHealthTerminalDesc3
    string InteractiveType		Usable
    string RadarDescription		HealthTerminalRadar
}

OBJECT IdryllEnergyTerminal		IdryllEnvironment
{
    string Description1		IdryllEnergyTerminalDesc1
    string Description2		IdryllEnergyTerminalDesc2
    string Description3		IdryllEnergyTerminalDesc3
    string InteractiveType		Usable
    string RadarDescription		EnergyTerminalRadar
}

OBJECT HoldIdryllM6EliteRifleShield		Animations
{
    string Aim		gauntlet_ffshield_idle
    float AimTimeMax		-1
    float AimTimeMin		-1
    string CombatBackpedal		swat_backpedal
    string CombatGunIdle		shield_idle
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		shield_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string Draw		gauntlet_ffshield_draw
    string Fire		gauntlet_ffshield_fire
    float FireTimeMax		-1
    float FireTimeMin		-1
    string Idle		gauntlet_ffshield_idle
    string IdleBackpedal		backpedal
    string IdleGunIdle		shield_idle
    string IdleLStrafe		strafe_left
    string IdleLegIdle		shield_idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    float InitialSpreadX		1
    float InitialSpreadY		1
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    string Melee		gauntlet_shield_meleecombo
    string PostFire		gauntlet_ffshield_postfire
    string PreFire		gauntlet_ffshield_prefire
    string PutAway		gauntlet_ffshield_putaway
    float ShotCount		2
    float SpreadMultiplier		1
    float spreadx		2
    float spready		2
}

OBJECT IdryllSabotageDevice		IdryllEnvironment
{
    string Description1		IdryllSabotageDeviceDesc1
    string Description2		IdryllSabotageDeviceDesc2
    string Description3		IdryllSabotageDeviceDesc3
    string RadarDescription		IdryllSabotageDeviceRadar
    string InteractiveType		TricorderUsable
}

OBJECT ShuttleDoorControlUsed		DallasEnvironment
{
    string Description1		ShuttleDoorControlUsedDesc1
    string Description2		ShuttleDoorControlUsedDesc2
    string Description3		ShuttleDoorControlUsedDesc3
    string InteractiveType		NonInteractive
    string RadarDescription		ShuttleDoorControlsRadar
}

OBJECT CargoDoorControlUsed		DallasEnvironment
{
    string Description1		CargoDoorControlUsedDesc1
    string Description2		CargoDoorControlUsedDesc2
    string Description3		CargoDoorControlUsedDesc3
    string InteractiveType		NonInteractive
    string RadarDescription		CargoDoorControlsRadar
}

OBJECT EngineeringControlsUsed		DallasEnvironment
{
    string Description1		EngineeringControlsUsedDesc1
    string Description2		EngineeringControlsUsedDesc2
    string Description3		EngineeringControlsUsedDesc3
    string InteractiveType		NonInteractive
    string RadarDescription		EngineeringControlsRadar
}

OBJECT IdryllGasControl		IdryllEnvironment
{
    string Description1		IdryllGasControlDesc1
    string Description2		IdryllGasControlDesc2
    string Description3		IdryllGasControlDesc3
    string InteractiveType		TricorderUsable
    string RadarDescription		IdryllGasControlRadar
}

OBJECT GravityControlsUsed		DallasEnvironment
{
    string Description1		GravityControlsUsedDesc1
    string Description2		GravityControlsUsedDesc2
    string Description3		GravityControlsUsedDesc3
    string InteractiveType		NonInteractive
    string RadarDescription		GravityControlsRadar
}

OBJECT TransporterControls		DallasEnvironment
{
    string Description1		TransporterControlsDesc1
    string Description2		TransporterControlsDesc2
    string Description3		TransporterControlsDesc3
    string InteractiveType		Usable
    string RadarDescription		TransporterControlsRadar
}

OBJECT TurboliftControlGridUsed		DallasEnvironment
{
    string Description1		TurboliftControlGridUsedDesc1
    string Description2		TurboliftControlGridUsedDesc2
    string Description3		TurboliftControlGridUsedDesc3
    string InteractiveType		NonInteractive
    string RadarDescription		TurboLiftControlGridRadar
}

OBJECT TransporterControlsUsed		DallasEnvironment
{
    string Description1		TransporterControlsUsedDesc1
    string Description2		TransporterControlsUsedDesc2
    string Description3		TransporterControlsUsedDesc3
    string InteractiveType		NonInteractive
    string RadarDescription		TransporterControlsRadar
}

OBJECT Snake		Aliens
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    string Description2		SnakeDesc2
    string Description3		SnakeDesc3
    string InteractiveType		Enemy
    float PainChance		1
    string RadarDescription		SnakeRadar
    float fov		360
    float health		3500
    float playerhatemodifier		1.5
    float visiondistance		65535
}

OBJECT Crab		Aliens
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    string Description2		CrabDesc2
    string Description3		CrabDesc3
    string InteractiveType		Enemy
    float PainChance		1
    string RadarDescription		CrabRadar
    float fov		360
    float health		60
    float playerhatemodifier		1.5
    float visiondistance		65535
}

OBJECT CrabBoss		Aliens
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    string Description2		CrabBossDesc2
    string Description3		CrabBossDesc3
    string InteractiveType		Enemy
    float PainChance		1
    string RadarDescription		CrabBossRadar
    float fov		360
    float health		1000
    float playerhatemodifier		1.5
    float visiondistance		65535
}

OBJECT Suldock		NPC
{
    float Description2		1
    float Description3		1
    string InteractiveType		Enemy
    float health		1000
}

OBJECT IdryllBridgePower		IdryllEnvironment
{
    string InteractiveType		Usable
    string Description1		IdryllBridgePowerDesc1
    string Description2		IdryllBridgePowerDesc2
    string Description3		IdryllBridgePowerDesc3
    string RadarDescription		IdryllBridgePowerRadar
}

OBJECT Waypoint		IdryllEnvironment
{
    string InteractiveType		Location
}

OBJECT HoldTricorder		Animations
{
    string Aim		tricorder_aim
    string CombatBackpedal		swat_backpedal
    string CombatGunIdle		tricorder_tense_idle
    float CombatGunTwitch		1
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		swat_calm_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string Draw		tricorder_draw
    string Fire		tricorder_use
    float FireTimeMax		1
    float FireTimeMin		1
    string Idle		tricorder_calm_idle
    string IdleBackpedal		backpedal
    string IdleGunIdle		tricorder_calm_idle
    float IdleGunTwitch		1
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    string Melee		tricorder_melee
    string PostFire		tricorder_postfire
    string PreFire		tricoder_prefire
    string PutAway		tricorder_putaway
    float ShotCount		0
    float spreadx		1
    float spready		1
}

OBJECT GravityPanel		DallasEnvironment
{
    string Description1		GravityPanelDesc1
    string Description2		GravityPanelDesc2
    string Description3		GravityPanelDesc3
    string InteractiveType		Usable
    string RadarDescription		GravityPanelRadar
}

OBJECT TurboliftPanel		DallasEnvironment
{
    string Description1		TurboliftPanelDesc1
    string Description2		TurboliftPanelDesc2
    string Description3		TurboliftPanelDesc3
    string InteractiveType		Usable
    string RadarDescription		TurboliftPanelRadar
}

OBJECT IdryllM6RebelMaleShield		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    string Description2		IdryllRebelMaleDesc2
    string Description3		IdryllRebelMaleDesc3
    float Description1		1
    string InteractiveType		Enemy
    float fov		360
    float health		80
    float playerhatemodifier		1.5
    float visiondistance		2048
    string RadarDescription		IdryllRebel1Radar
}

OBJECT IdryllM6RebelFemaleShield		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    string Description2		IdryllRebelFemaleDesc2
    string Description3		IdryllRebelFemaleDesc3
    float Description1		1
    string InteractiveType		Enemy
    float fov		360
    float health		80
    float playerhatemodifier		1.5
    float visiondistance		2048
    string RadarDescription		IdryllRebel2Radar
}

OBJECT IdryllM6EliteFemaleShield		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    string Description3		IdryllRebelFemaleDesc3
    string Description2		IdryllRebelFemaleDesc2
    float Description1		1
    string InteractiveType		Enemy
    float fov		360
    float health		90
    float playerhatemodifier		1.5
    float visiondistance		2048
    string RadarDescription		IdryllRebel2Radar
}

OBJECT IdryllM6EliteMaleShield		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    string Description3		IdryllRebelMaleDesc3
    string Description2		IdryllRebelMaleDesc2
    float Description1		1
    string InteractiveType		Enemy
    float fov		360
    float health		90
    float playerhatemodifier		1.5
    float visiondistance		2048
    string RadarDescription		IdryllRebel1Radar
}

OBJECT IdryllEnergyTerminal2		IdryllEnvironment
{
    string Description1		IdryllEnergyTerminal2Desc1
    string Description2		IdryllEnergyTerminal2Desc2
    string Description3		IdryllEnergyTerminal2Desc3
    string InteractiveType		Usable
    string RadarDescription		IdryllEnergyTerminal2Radar
}

OBJECT AndorianMerc		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    string Description2		AndorianMercDesc2
    string Description3		AndorianMercDesc3
    string InteractiveType		Enemy
    float fov		360
    float health		80
    float playerhatemodifier		1.5
    float visiondistance		2048
}

OBJECT HumanMercMale		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    string Description2		HumanMercMaleDesc2
    string Description3		HumanMercMaleDesc3
    string InteractiveType		Enemy
    float fov		360
    float health		30
    float playerhatemodifier		1.5
    float visiondistance		2048
}

OBJECT HumanMercFemale		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    string Description2		HumanMercFemaleDesc2
    string Description3		HumanMercFemaleDesc3
    string InteractiveType		Enemy
    float fov		360
    float health		30
    float playerhatemodifier		1.5
    float visiondistance		2048
}

OBJECT CustomShaderTest		CustomShaders
{
    string ShaderName		powerup_strength
    string SoundName		sound/environment/electric/fritz5.wav
}

OBJECT PicardM6Bridge		NPC
{
    string Description2		PicardDesc2
    string Description1		PicardDesc1
    string Description3		PicardDesc3
    string InteractiveType		Friendly
    float PainChance		0
    string RadarDescription		PicardRadar
    float fov		360
    float health		400
    float playerhatemodifier		1
    float visiondistance		3600
}

OBJECT RomulanTricorderDoor		RomulanEnvironment
{
    string Description1		RomulanTricorderDoorDesc1
    string Description2		RomulanTricorderDoorDesc2
    string Description3		RomulanTricorderDoorDesc3
    string InteractiveType		TricorderUsable
}

OBJECT StarfleetMale		NPC
{
    float fov		360
    float visiondistance		1200
    float health		1000
    string Description1		StarfleetMaleDesc1
    string Description2		StarfleetMaleDesc2
    string Description3		StarfleetMaleDesc3
    string InteractiveType		Friendly
    string RadarDescription		StarfleetMaleRadar
}

OBJECT StarfleetMale2		NPC
{
    float fov		360
    float visiondistance		1200
    float health		1000
    string Description1		StarfleetMale2Desc1
    string Description2		StarfleetMale2Desc2
    string Description3		StarfleetMale2Desc3
    string InteractiveType		Friendly
    string RadarDescription		StarfleetMale2Radar
}

OBJECT StarfleetMale3		NPC
{
    float fov		360
    float visiondistance		1200
    float health		1000
    string Description1		StarfleetMale3Desc1
    string Description2		StarfleetMale3Desc2
    string Description3		StarfleetMale3Desc3
    string InteractiveType		Friendly
    string RadarDescription		StarfleetMale3Radar
}

OBJECT StarfleetMale4		NPC
{
    float fov		360
    float visiondistance		1200
    float health		1000
    string InteractiveType		Friendly
    string Description1		StarfleetMale4Desc1
    string Description2		StarfleetMale4Desc2
    string Description3		StarfleetMale4Desc3
    string RadarDescription		StarfleetMale4Radar
}

OBJECT StarfleetMale5		NPC
{
    float fov		360
    float visiondistance		1200
    float health		1000
    string InteractiveType		Friendly
    string Description1		StarfleetMale5Desc1
    string Description2		StarfleetMale5Desc2
    string Description3		StarfleetMale5Desc3
    string RadarDescription		StarfleetMale5Radar
}

OBJECT StarfleetMale6		NPC
{
    string InteractiveType		Friendly
    float fov		360
    float health		1000
    string Description1		StarfleetMale6Desc1
    string Description2		StarfleetMale6Desc2
    string Description3		StarfleetMale6Desc3
    float visiondistance		1200
    string RadarDescription		StarfleetMale6Radar
}

OBJECT StarfleetFemale		NPC
{
    float visiondistance		1200
    string Description1		StarfleetFemaleDesc1
    string Description2		StarfleetFemaleDesc2
    string Description3		StarfleetFemaleDesc3
    string InteractiveType		Friendly
    float fov		360
    float health		1000
    string RadarDescription		StarfleetFemaleRadar
}

OBJECT StarfleetFemale2		NPC
{
    float visiondistance		1200
    float health		1000
    float fov		360
    string InteractiveType		Friendly
    string Description1		StarfleetFemale2Desc1
    string Description2		StarfleetFemale2Desc2
    string Description3		StarfleetFemale2Desc3
    string RadarDescription		StarfleetFemale2Radar
}

OBJECT StarfleetFemale3		NPC
{
    float visiondistance		1200
    float fov		360
    float health		1000
    string InteractiveType		Friendly
    string Description1		StarfleetFemale3Desc1
    string Description2		StarfleetFemale3Desc2
    string Description3		StarfleetFemale3Desc3
    string RadarDescription		StarfleetFemale3Radar
}

OBJECT StarfleetFemale4		NPC
{
    float visiondistance		1200
    float fov		360
    float health		1000
    string InteractiveType		Friendly
    string Description1		StarfleetFemale4Desc1
    string Description2		StarfleetFemale4Desc2
    string Description3		StarfleetFemale4Desc3
    string RadarDescription		StarfleetFemale4Radar
}

OBJECT StarfleetFemale5		NPC
{
    float visiondistance		1200
    float fov		360
    float health		1000
    string InteractiveType		Friendly
    string Description1		StarfleetFemale5Desc1
    string Description2		StarfleetFemale5Desc2
    string Description3		StarfleetFemale5Desc3
    string RadarDescription		StarfleetFemale5Radar
}

OBJECT StarfleetFemale6		NPC
{
    float visiondistance		1200
    float fov		360
    float health		1000
    string InteractiveType		Friendly
    string Description1		StarfleetFemale6Desc1
    string Description2		StarfleetFemale6Desc2
    string Description3		StarfleetFemale6Desc3
    string RadarDescription		StarfleetFemale6Radar
}

OBJECT StarfleetDeadCaptain		NPC
{
    string Description1		StarfleetDeadCaptainDesc1
    string Description2		StarfleetDeadCaptainDesc2
    string Description3		StarfleetDeadCaptainDesc3
    string InteractiveType		Friendly
    float fov		360
    float health		1000
    float visiondistance		1200
    float PainChance		0
}

OBJECT IdryllGasControlUsed		IdryllEnvironment
{
    string Description1		IdryllGasControlUsedDesc1
    string Description2		IdryllGasControlUsedDesc2
    string Description3		IdryllGasControlUsedDesc3
    string InteractiveType		NonInteractive
    string RadarDescription		IdryllGasControlRadar
}

OBJECT IdryllPowerRegulatorUsed		IdryllEnvironment
{
    string Description1		IdryllPowerRegulatorUsedDesc1
    string Description2		IdryllPowerRegulatorUsedDesc2
    string Description3		IdryllPowerRegulatorUsedDesc3
    string InteractiveType		NonInteractive
    string RadarDescription		IdryllPowerRegulatorRadar
}

OBJECT IdryllPowerPanelUsed		IdryllEnvironment
{
    string Description1		IdryllPowerPanelUsedDesc1
    string Description2		IdryllPowerPanelUsedDesc2
    string Description3		IdryllPowerPanelUsedDesc3
    string InteractiveType		NonInteractive
    string RadarDescription		PowerPanelRadar
}

OBJECT StarfleetCadetMale		NPC
{
    string Description1		StarfleetCadetMaleDesc1
    string Description2		StarfleetCadetMaleDesc2
    string Description3		StarfleetCadetMaleDesc3
    string InteractiveType		Friendly
    float visiondistance		1200
    float health		1000
    float fov		360
    string RadarDescription		StarfleetCadetMaleRadar
}

OBJECT StarfleetCadetMale2		NPC
{
    string Description1		StarfleetCadetMale2Desc1
    string Description2		StarfleetCadetMale2Desc2
    string Description3		StarfleetCadetMale2Desc3
    string InteractiveType		Friendly
    float fov		360
    float health		1000
    float visiondistance		1200
    string RadarDescription		StarfleetCadetMale2Radar
}

OBJECT StarfleetCadetMale3		NPC
{
    string Description1		StarfleetCadetMale3Desc1
    string Description2		StarfleetCadetMale3Desc2
    string Description3		StarfleetCadetMale3Desc3
    string InteractiveType		Friendly
    float fov		360
    float health		1000
    float visiondistance		1200
    string RadarDescription		StarfleetCadetMale3Radar
}

OBJECT StarfleetCadetFemale		NPC
{
    string Description1		StarfleetCadetFemaleDesc1
    string Description2		StarfleetCadetFemaleDesc2
    string Description3		StarfleetCadetFemaleDesc3
    string InteractiveType		Friendly
    float fov		360
    float health		1000
    float visiondistance		1200
    string RadarDescription		StarfleetCadetFemaleRadar
}

OBJECT StarfleetCadetFemale2		NPC
{
    float visiondistance		1200
    float health		1000
    float fov		360
    string InteractiveType		Friendly
    string Description1		StarfleetCadetFemale2Desc1
    string Description2		StarfleetCadetFemale2Desc2
    string Description3		StarfleetCadetFemale2Desc3
    string RadarDescription		StarfleetCadetFemale2Radar
}

OBJECT StarfleetCadetFemale3		NPC
{
    float visiondistance		1200
    float health		1000
    float fov		360
    string InteractiveType		Friendly
    string Description1		StarfleetCadetFemale3Desc1
    string Description2		StarfleetCadetFemale3Desc2
    string Description3		StarfleetCadetFemale3Desc3
    string RadarDescription		StarfleetCadetFemale3Radar
}

OBJECT StarfleetOfficialFemale		NPC
{
    float visiondistance		1200
    float health		1000
    float fov		360
    string InteractiveType		Friendly
    string Description1		StarfleetOfficialFemaleDesc1
    string Description2		StarfleetOfficialFemaleDesc2
    string Description3		StarfleetOfficialFemaleDesc3
    string RadarDescription		StarfleetOfficialFemaleRadar
}

OBJECT StarfleetOfficialFemale2		NPC
{
    float visiondistance		1200
    float health		1000
    float fov		360
    string InteractiveType		Friendly
    string Description1		StarfleetOfficialFemale2Desc1
    string Description2		StarfleetOfficialFemale2Desc2
    string Description3		StarfleetOfficialFemale2Desc3
    string RadarDescription		StarfleetOfficialFemale2Radar
}

OBJECT StarfleetOfficialFemale3		NPC
{
    float visiondistance		1200
    float health		1000
    float fov		360
    string InteractiveType		Friendly
    string Description1		StarfleetOfficialFemale3Desc1
    string Description2		StarfleetOfficialFemale3Desc2
    string Description3		StarfleetOfficialFemale3Desc3
    string RadarDescription		StarfleetOfficialFemale3Radar
}

OBJECT StarfleetOfficialMale		NPC
{
    float visiondistance		1200
    float health		1000
    float fov		360
    string InteractiveType		Friendly
    string Description1		StarfleetOfficialMaleDesc1
    string Description2		StarfleetOfficialMaleDesc2
    string Description3		StarfleetOfficialMaleDesc3
    string RadarDescription		StarfleetOfficialMaleRadar
}

OBJECT StarfleetOfficialMale2		NPC
{
    float visiondistance		1200
    float health		1000
    float fov		360
    string InteractiveType		Friendly
    string Description1		StarfleetOfficialMale2Desc1
    string Description2		StarfleetOfficialMale2Desc2
    string Description3		StarfleetOfficialMale2Desc3
    string RadarDescription		StarfleetOfficialMale2Radar
}

OBJECT StarfleetTeacherMale		NPC
{
    string Description1		StarfleetTeacherMaleDesc1
    string Description2		StarfleetTeacherMaleDesc2
    string Description3		StarfleetTeacherMaleDesc3
    string InteractiveType		Friendly
    float fov		360
    float health		1000
    float visiondistance		1200
    string RadarDescription		StarfleetTeacherMaleRadar
}

OBJECT StarfleetTeacherMale2		NPC
{
    float visiondistance		1200
    float health		1000
    float fov		360
    string InteractiveType		Friendly
    string Description1		StarfleetTeacherMale2Desc1
    string Description2		StarfleetTeacherMale2Desc2
    string Description3		StarfleetTeacherMale2Desc3
    string RadarDescription		StarfleetTeacherMale2Radar
}

OBJECT StarfleetTeacherMale3		NPC
{
    float visiondistance		1200
    float health		1000
    float fov		360
    string InteractiveType		Friendly
    string Description1		StarfleetTeacherMale3Desc1
    string Description2		StarfleetTeacherMale3Desc2
    string Description3		StarfleetTeacherMale3Desc3
    string RadarDescription		StarfleetTeacherMale3Radar
}

OBJECT StarfleetTeacherFemale		NPC
{
    float visiondistance		1200
    float health		1000
    float fov		360
    string InteractiveType		Friendly
    string Description1		StarfleetTeacherFemaleDesc1
    string Description2		StarfleetTeacherFemaleDesc2
    string Description3		StarfleetTeacherFemaleDesc3
    string RadarDescription		StarfleetTeacherFemaleRadar
}

OBJECT StarfleetTeacherFemale2		NPC
{
    float visiondistance		1200
    float health		1000
    float fov		360
    string InteractiveType		Friendly
    string Description1		StarfleetTeacherFemale2Desc1
    string Description2		StarfleetTeacherFemale2Desc2
    string Description3		StarfleetTeacherFemale2Desc3
    string RadarDescription		StarfleetTeacherFemale2Radar
}

OBJECT StarfleetTeacherFemale3		NPC
{
    float visiondistance		1200
    float health		1000
    float fov		360
    string InteractiveType		Friendly
    string Description1		StarfleetTeacherFemale3Desc1
    string Description2		StarfleetTeacherFemale3Desc2
    string Description3		StarfleetTeacherFemale3Desc3
    string RadarDescription		StarfleetTeacherFemale3Radar
}

OBJECT ContainmentPanel		FederationEnvironment
{
    string Description1		ContainmentPanelDesc1
    string Description2		ContainmentPanelDesc2
    string Description3		ContainmentPanelDesc3
    string InteractiveType		TricorderUsable
    string RadarDescription		ContainmentPanelRadar
}

OBJECT IdryllRebelBomber		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    string Description2		IdryllRebelDesc2
    string Description3		IdryllRebelDesc3
    string InteractiveType		Enemy
    string RadarDescription		IdryllRebelRadar
    float fov		360
    float health		5
    float playerhatemodifier		1.5
    float visiondistance		2048
}

OBJECT IdryllEliteDefender		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    string Description2		IdryllRebelDesc2
    string Description3		IdryllRebelDesc3
    string InteractiveType		Enemy
    string RadarDescription		IdryllRebelRadar
    float fov		360
    float health		75
    float playerhatemodifier		1.5
    float visiondistance		2048
}

OBJECT WarpCoreBleed		FederationEnvironment
{
    string Description1		WarpCoreBleedDesc1
    string Description2		WarpCoreBleedDesc2
    string Description3		WarpCoreBleedDesc3
    string InteractiveType		TricorderUsable
    string RadarDescription		WarpCoreBleedRadar
}

OBJECT WarpCoreEject		FederationEnvironment
{
    string Description1		WarpCoreEjectDesc1
    string Description2		WarpCoreEjectDesc2
    string Description3		WarpCoreEjectDesc3
    string InteractiveType		TricorderUsable
    string RadarDescription		WarpCoreEjectRadar
}

OBJECT HoldIdryllMGun		Animations
{
    string Aim		gauntlet_mortar_aim
    float AimTimeMax		-1
    float AimTimeMin		-1
    string CombatBackpedal		swat_backpedal
    string CombatGunIdle		idle
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		swat_calm_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string Draw		gauntlet_mortar_draw
    string Fire		gauntlet_mortar_fire
    float FireTimeMax		-1
    float FireTimeMin		-1
    string Idle		gauntlet_mortar_idle
    string IdleBackpedal		backpedal
    string IdleGunIdle		idle
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    string PostFire		gauntlet_mortar_postfire
    string PreFire		gauntlet_mortar_prefire
    string PutAway		gauntlet_mortar_putaway
    float spreadx		25
    float spready		25
    float ShotCount		8
}

OBJECT IdryllRebelGunnerFemale		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    string Description2		IdryllRebelDesc2
    string Description3		IdryllRebelDesc3
    string InteractiveType		Enemy
    string RadarDescription		IdryllRebelRadar
    float fov		360
    float health		75
    float playerhatemodifier		1.5
    float visiondistance		5000
}

OBJECT IdryllRebelGunnerMale		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    float Description1		1
    string Description2		IdryllRebelDesc2
    string Description3		IdryllRebelDesc3
    string InteractiveType		Enemy
    string RadarDescription		IdryllRebelRadar
    float fov		360
    float health		75
    float playerhatemodifier		1.5
    float visiondistance		5000
}

OBJECT HoldEnterpriseDatapad		Animations
{
    string Aim		ent-datapad-idle
    string CombatBackpedal		swat_backpedal
    string CombatGunIdle		ent-datapad-idle
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		swat_calm_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string Draw		ent-datapad-raise
    string Fire		ent-datapad-use
    string Idle		ent-datapad-idle
    string IdleGunIdle		ent-datapad-idle
    string IdleBackpedal		backpedal
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    string PutAway		ent-datapad-putaway
    float ShotCount		0
    float spreadx		1
    float spready		1
}

OBJECT AttrexianTriDoorPanel		AttrexianEnvironment
{
    string Description1		AttrexianTriDoorPanelDesc1
    string Description2		AttrexianTriDoorPanelDesc2
    string Description3		AttrexianTriDoorPanelDesc3
    string InteractiveType		TricorderUsable
    string RadarDescription		AttrexianTriDoorPanelRadar
}

OBJECT RomulanBossGuardM10Rifle		Humanoids
{
    OBJECT PainChance		DamageType
    {
    }

    string Description2		RomulanSnowGuardM10RifleDesc2
    float Description1		1
    string Description3		RomulanSnowGuardM10RifleDesc3
    string InteractiveType		Enemy
    float PainChance		1
    float RadarDescription		1
    float fov		360
    float health		25
    float playerhatemodifier		1.5
    float visiondistance		1200
}

OBJECT RomulanLiftControl		RomulanEnvironment
{
    string Description1		RomulanLiftControlDesc1
    string Description2		RomulanLiftControlDesc2
    string Description3		RomulanLiftControlDesc3
    string InteractiveType		Usable
    string RadarDescription		RomulanLiftControlRadar
}

OBJECT RomulanKeypad		RomulanEnvironment
{
    string Description1		RomulanKeypadDesc1
    string Description2		RomulanKeypadDesc2
    string Description3		RomulanKeypadDesc3
    string InteractiveType		TricorderUsable
    string RadarDescription		RomulanKeypadRadar
}

OBJECT Barclay		NPC
{
    string Description1		BarclayDesc1
    string Description2		BarclayDesc2
    string Description3		BarclayDesc3
    string InteractiveType		Friendly
    float fov		360
    float health		1000
    float visiondistance		1200
    string RadarDescription		BarclayRadar
}

OBJECT Redshirt		NPC
{
    string Description1		RedshirtDesc1
    string Description2		RedshirtDesc2
    string Description3		RedshirtDesc3
    string InteractiveType		Friendly
    float fov		360
    float health		1000
    float visiondistance		1200
    string RadarDescription		RedshirtRadar
}

OBJECT Redshirt2		NPC
{
    string Description1		Redshirt2Desc1
    string Description2		Redshirt2Desc2
    string Description3		Redshirt2Desc3
    string InteractiveType		Friendly
    float fov		360
    float health		1000
    float visiondistance		1200
    string RadarDescription		Redshirt2Radar
}

OBJECT Redshirt3		NPC
{
    string Description1		Redshirt3Desc1
    string Description2		Redshirt3Desc2
    string Description3		Redshirt3Desc3
    string InteractiveType		Friendly
    float fov		360
    float health		1000
    float visiondistance		1200
    string RadarDescription		Redshirt3Radar
}

OBJECT Redshirt4		NPC
{
    string Description1		Redshirt4Desc1
    string Description2		Redshirt4Desc2
    string Description3		Redshirt4Desc3
    string InteractiveType		Friendly
    float fov		360
    float health		1000
    float visiondistance		1200
    string RadarDescription		Redshirt4Radar
}

OBJECT Redshirt5		NPC
{
    string Description1		Redshirt5Desc1
    string Description2		Redshirt5Desc2
    string Description3		Redshirt5Desc3
    string InteractiveType		Friendly
    float fov		360
    float health		1000
    float visiondistance		1200
    string RadarDescription		Redshirt5Radar
}

OBJECT Redshirt6		NPC
{
    string Description1		Redshirt6Desc1
    string Description2		Redshirt6Desc2
    string Description3		Redshirt6Desc3
    string InteractiveType		Friendly
    float fov		360
    float health		1000
    float visiondistance		1200
    string RadarDescription		Redshirt6Radar
}

OBJECT HazardLocker		FederationEnvironment
{
    string Description1		HazardLockerDesc1
    string Description2		HazardLockerDesc2
    string Description3		HazardLockerDesc3
    string InteractiveType		TricorderUsable
    string RadarDescription		HazardLockerRadar
}

OBJECT AttrexianDoorOverride		AttrexianEnvironment
{
    string Description1		AttrexianDoorOverrideDesc1
    string Description2		AttrexianDoorOverrideDesc2
    string Description3		AttrexianDoorOverrideDesc3
    string InteractiveType		TricorderUsable
    string RadarDescription		AttrexianDoorOverrideRadar
}

OBJECT RomulanInformantBoss		Humanoids
{
}

OBJECT RomulanKeypadNoninteractive		RomulanEnvironment
{
    string Description1		RomulanKeypadNoninteractiveDesc1
    string Description2		RomulanKeypadNoninteractiveDesc2
    string Description3		RomulanKeypadNoninteractiveDesc3
    string InteractiveType		NonInteractive
    string RadarDescription		RomulanKeypadRadar
}

OBJECT CredentialPanel		RomulanEnvironment
{
    string Description1		CredentialPanelDesc1
    string Description2		CredentialPanelDesc2
    string Description3		CredentialPanelDesc3
    string InteractiveType		TricorderUsable
    string RadarDescription		CredentialPanelRadar
}

OBJECT CredentialPanelNoninteractive		RomulanEnvironment
{
    string Description1		CredentialPanelNoninteractiveDesc1
    string Description2		CredentialPanelNoninteractiveDesc2
    string Description3		CredentialPanelNoninteractiveDesc3
    string InteractiveType		NonInteractive
    string RadarDescription		CredentialPanelRadar
}

OBJECT RomulanSecurityGrid		RomulanEnvironment
{
    string Description1		RomulanSecurityGridDesc1
    string Description2		RomulanSecurityGridDesc2
    string Description3		RomulanSecurityGridDesc3
    string InteractiveType		TricorderUsable
    string RadarDescription		SecurityGridRadar
}

OBJECT RomulanSecurityGridNoninteractive		RomulanEnvironment
{
    string Description1		RomulanSecurityGridNoninteractiveDesc1
    string Description2		RomulanSecurityGridNoninteractiveDesc2
    string Description3		RomulanSecurityGridNoninteractiveDesc3
    string InteractiveType		NonInteractive
    string RadarDescription		SecurityGridRadar
}

OBJECT RomulanSecurityConsoleNoninteractive		RomulanEnvironment
{
    string Description1		RomulanSecurityConsoleNoninteractiveDesc1
    string Description2		RomulanSecurityConsoleNoninteractiveDesc1
    string Description3		RomulanSecurityConsoleNoninteractiveDesc1
    string InteractiveType		NonInteractive
    string RadarDescription		SecurityConsoleRadar
}

OBJECT RomulanConsoleUsed		RomulanEnvironment
{
    string Description1		RomulanConsoleUsedDesc1
    string Description2		RomulanConsoleUsedDesc2
    string Description3		RomulanConsoleUsedDesc3
    string InteractiveType		NonInteractive
    string RadarDescription		RomulanConsoleRadar
}

OBJECT LadderReleaseSwitch		AttrexianEnvironment
{
    string Description1		LadderReleaseSwitchDesc1
    string Description2		LadderReleaseSwitchDesc2
    string Description3		LadderReleaseSwitchDesc3
    string InteractiveType		TricorderUsable
    string RadarDescription		LadderReleaseRadar
}

OBJECT LadderReleaseSwitchUsed		AttrexianEnvironment
{
    string Description1		LadderReleaseSwitchUsedDesc1
    string Description2		LadderReleaseSwitchUsedDesc2
    string Description3		LadderReleaseSwitchUsedDesc3
    string InteractiveType		NonInteractive
    string RadarDescription		LadderReleaseRadar
}

OBJECT AttrexianCartPanelUsed		AttrexianEnvironment
{
    string Description1		AttrexianCartPanelUsedDesc1
    string Description2		AttrexianCartPanelUsedDesc2
    string Description3		AttrexianCartPanelUsedDesc3
    string InteractiveType		NonInteractive
    string RadarDescription		AttrexianCartPanelRadar
}

OBJECT AttrexianCartLeverUsed		AttrexianEnvironment
{
    string Description1		AttrexianCartLeverUsedDesc1
    string Description2		AttrexianCartLeverUsedDesc2
    string Description3		AttrexianCartLeverUsedDesc3
    string InteractiveType		NonInteractive
    string RadarDescription		AttrexianCartLeverRadar
}

OBJECT AttrexianPowerPanelUsed		AttrexianEnvironment
{
    string Description1		AttrexianPowerPanelUsedDesc1
    string Description2		AttrexianPowerPanelUsedDesc2
    string Description3		AttrexianPowerPanelUsedDesc3
    string InteractiveType		NonInteractive
    string RadarDescription		AttrexianPowerPanelRadar
}

OBJECT AttrexianSteamPanelUsed		AttrexianEnvironment
{
    string Description1		AttrexianSteamPanelUsedDesc1
    string Description2		AttrexianSteamPanelUsedDesc2
    string Description3		AttrexianSteamPanelUsedDesc3
    string InteractiveType		NonInteractive
    string RadarDescription		AttrexianSteamPanelRadar
}

OBJECT AttrexianDoorOverrideUsed		AttrexianEnvironment
{
    string Description1		AttrexianDoorOverrideUsedDesc1
    string Description2		AttrexianDoorOverrideUsedDesc2
    string Description3		AttrexianDoorOverrideUsedDesc3
    string InteractiveType		NonInteractive
    string RadarDescription		AttrexianDoorOverrideRadar
}

OBJECT AttrexianTriDoorPanelUsed		AttrexianEnvironment
{
    string Description1		AttrexianTriDoorPanelUsedDesc1
    string Description2		AttrexianTriDoorPanelUsedDesc2
    string Description3		AttrexianTriDoorPanelUsedDesc3
    string InteractiveType		NonInteractive
    string RadarDescription		AttrexianTriDoorPanelRadar
}

OBJECT AttrexianPistonPanel		AttrexianEnvironment
{
    string Description1		AttrexianPistonPanelDesc1
    string Description2		AttrexianPistonPanelDesc2
    string Description3		AttrexianPistonPanelDesc3
    string InteractiveType		Usable
    string RadarDescription		AttrexianPistonPanelRadar
}

OBJECT TrainingTuvok		NPC
{
    string Description1		TrainingTuvokDesc1
    string Description2		TrainingTuvokDesc2
    string Description3		TrainingTuvokDesc3
    string InteractiveType		Teammate
    string RadarDescription		TuvokRadar
    float fov		360
    float health		100
    float playerhatemodifier		1.5
    float visiondistance		1200
}

OBJECT RomulanTricorderDoorNoninteractive		RomulanEnvironment
{
    string Description1		RomulanTricorderDoorNoninteractiveDesc1
    string Description2		RomulanTricorderDoorNoninteractiveDesc2
    string Description3		RomulanTricorderDoorNoninteractiveDesc3
    string InteractiveType		NonInteractive
}

OBJECT IdryllTriLiftPanel		IdryllEnvironment
{
    string Description1		IdryllTriLiftPanelDesc1
    string Description2		IdryllTriLiftPanelDesc2
    string Description3		IdryllTriLiftPanelDesc3
    string InteractiveType		TricorderUsable
    string RadarDescription		TriLiftPanelRadar
}

OBJECT RomulanGenericConsole		RomulanEnvironment
{
    string Description1		RomulanGenericConsoleDesc1
    string Description2		RomulanGenericConsoleDesc2
    string Description3		RomulanGenericConsoleDesc3
    string InteractiveType		TricorderUsable
    string RadarDescription		RomulanGenericConsoleRadar
}

OBJECT HoldRomulanDisruptorM2		Animations
{
    string Aim		romdisruptor_aim
    float AimTimeMax		0.3
    float AimTimeMin		0.25
    string CombatBackpedal		swat_backpedal
    string CombatGunIdle		romdisruptor_tense_idle
    string CombatLStrafe		swat_lstrafe
    string CombatLegIdle		swat_calm_idle
    string CombatRStrafe		swat_rstrafe
    string CombatRun		swat_run
    string CombatWalk		swat_walk
    string Draw		romdisruptor_draw
    string Fire		romdisruptor_fire
    float FireTimeMax		1.25
    float FireTimeMin		1
    string Idle		romdisruptor_idle
    string IdleBackpedal		backpedal
    string IdleGunIdle		romdisruptor_calm_idle
    string IdleLStrafe		strafe_left
    string IdleLegIdle		idle
    string IdleRStrafe		strafe_right
    string IdleRun		run
    string IdleWalk		walk
    float MaxTorsoPitch		40
    float MaxTorsoTurnSpeed		15
    float MaxTorsoYaw		80
    string Melee		romdisruptor_melee
    string PostFire		romdisruptor_postfire
    string PreFire		romdisruptor_prefire
    string PutAway		romdisruptor_putaway
    float ShotCount		3
    float spreadx		20
    float spready		20
}

OBJECT LibraryTerminal		FederationEnvironment
{
    string Description1		LibraryTerminalDesc1
    string Description2		LibraryTerminalDesc2
    string Description3		LibraryTerminalDesc3
    string InteractiveType		Usable
    string RadarDescription		LibraryTerminalRadar
}

OBJECT PredatorNoRadar		Aliens
{
    float Description1		1
    string Description2		StalkerDesc2
    string Description3		StalkerDesc3
    string InteractiveType		NonInteractive
    float PainChance		1
    string RadarDescription		StalkerRadar
    float fov		360
    float health		1500
    float playerhatemodifier		1.5
    float visiondistance		1200
}

OBJECT TriTrainingPowerPanel		FederationEnvironment
{
    string Description1		TriTrainingPowerPanelDesc1
    string Description2		TriTrainingPowerPanelDesc2
    string Description3		TriTrainingPowerPanelDesc3
    string InteractiveType		TricorderUsable
    string RadarDescription		TriTrainingPowerPanelRadar
}

OBJECT DrullLiftControl		IdryllEnvironment
{
    string Description1		DrullLiftControlDesc1
    string Description2		DrullLiftControlDesc2
    string Description3		DrullLiftControlDesc3
    string InteractiveType		Usable
    string RadarDescription		DrullLiftControlRadar
}

OBJECT TriDrullLiftControl		IdryllEnvironment
{
    string Description1		TriDrullLiftControlDesc1
    string Description2		TriDrullLiftControlDesc2
    string Description3		TriDrullLiftControlDesc3
    string InteractiveType		TricorderUsable
    string RadarDescription		TriDrullLiftControlRadar
}

OBJECT StarfleetCadetFemale4		NPC
{
    string Description1		StarfleetCadetFemale4Desc1
    string Description2		StarfleetCadetFemale4Desc2
    string Description3		StarfleetCadetFemale4Desc3
    string InteractiveType		Friendly
    string RadarDescription		StarfleetCadetFemale4Radar
}

OBJECT StarfleetCadetFemale5		NPC
{
    string Description1		StarfleetCadetFemale5Desc1
    string Description2		StarfleetCadetFemale5Desc2
    string Description3		StarfleetCadetFemale5Desc3
    string InteractiveType		Friendly
    string RadarDescription		StarfleetCadetFemale5Radar
}

OBJECT Harry		NPC
{
    string Description1		HarryDesc1
    string Description2		HarryDesc2
    string Description3		HarryDesc3
    string InteractiveType		Friendly
    string RadarDescription		HarryRadar
    float health		1000
    float fov		360
}

OBJECT TransportOutBorgNoAnim		DisplayEffects
{
    float AttachEffect		0
    string EffectName		fx/fx-beamsparkle-borg-out.tik
    string EffectPosName		Bip01
    float EffectTime		0.25
    string ShaderName		transport-borg
    string SoundName		snd_bodytransportout
    float TransportTime		0.75
    float HideFeatures		1
}

OBJECT TransportInBorgNoAnim		DisplayEffects
{
    float AttachEffect		0
    string EffectName		fx/fx-beamsparkle-borg-in.tik
    string EffectPosName		centroid
    float EffectTime		0.75
    float Immobilize		1
    string ShaderName		transport-borg
    string SoundName		snd_bodytransportin
    float TransportTime		0.75
    float HideFeatures		1
}

OBJECT RomulanTSectorSign		RomulanEnvironment
{
    string Description1		RomulanTSectorSignDesc1
    string Description2		RomulanTSectorSignDesc2
    string InteractiveType		TricorderUsable
}

OBJECT TrainingPanel2		FederationEnvironment
{
    string Description1		TrainingPanelDesc1
    string Description2		TrainingPanelDesc2
    string Description3		TrainingPanelDesc3
    string InteractiveType		TricorderUsable
    string RadarDescription		TrainingPanelRadar
}

OBJECT NonInteractiveNoReticule		InteractiveTypes
{
    float AlwaysShowReticle		0
    float BlipShader		1
    float Blue		0.6
    float Green		0.42
    float Red		0.85
    float ShowInRadar		0
    float ShowInSimpleMode		0
}

OBJECT Vorchov		NPC
{
    string Description1		VorchovDesc1
    string Description2		VorchovDesc2
    string Description3		VorchovDesc3
    string InteractiveType		Friendly
    string RadarDescription		VorchovRadar
}

OBJECT koi1		FederationEnvironment
{
    string Description2		koi1Desc2
    string Description3		koi1Desc3
    string InteractiveType		NonInteractive
    string RadarDescription		koi1Radar
}

OBJECT koi2		FederationEnvironment
{
    string Description2		koi2Desc2
    string Description3		koi2Desc3
    string InteractiveType		NonInteractive
    string RadarDescription		koi2Radar
}

OBJECT koi3		FederationEnvironment
{
    string InteractiveType		NonInteractive
    string RadarDescription		koi3Radar
    string Description2		koi3Desc2
    string Description3		koi3Desc3
}

OBJECT koi4		FederationEnvironment
{
    string InteractiveType		NonInteractive
    string RadarDescription		koi4Radar
    string Description2		koi4Desc2
    string Description3		koi4Desc3
}

OBJECT koi5		FederationEnvironment
{
    string InteractiveType		NonInteractive
    string RadarDescription		koi5Radar
    string Description2		koi5Desc2
    string Description3		koi5Desc3
}

OBJECT koi6		FederationEnvironment
{
    string InteractiveType		NonInteractive
    string RadarDescription		koi6Radar
    string Description2		koi6Desc2
    string Description3		koi6Desc3
}

OBJECT koi7		FederationEnvironment
{
    string InteractiveType		NonInteractive
    string RadarDescription		koi7Radar
    string Description2		koi7Desc2
    string Description3		koi7Desc3
}

OBJECT FadeOutSimple		DisplayEffects
{
    float AttachEffect		0
    float EffectTime		0
    float FadeTime		0.5
    float Immobilize		0
    float NumEffects		0
}

OBJECT FadeInSimple		DisplayEffects
{
    float AttachEffect		0
    float EffectTime		0
    float FadeTime		0.5
    float Immobilize		0
    float NumEffects		0
}

OBJECT AttrexianRifleSecretPic		Secret
{
    string InteractiveType		NonInteractive
    string Description1		AttrexianRifleSecretPicDesc1
    string Description2		AttrexianRifleSecretPicDesc2
    string Description3		AttrexianRifleSecretPicDesc3
    string RadarDescription		AttrexianRifleSecretPicRadar
}

OBJECT AttrexianColonySecretPic		Secret
{
    string InteractiveType		NonInteractive
    string Description1		AttrexianColonySecretPicDesc1
    string Description2		AttrexianColonySecretPicDesc2
    string Description3		AttrexianColonySecretPicDesc3
    string RadarDescription		AttrexianColonySecretPicRadar
}

OBJECT AttrexianStationSecretPic		Secret
{
    string InteractiveType		NonInteractive
    string Description1		AttrexianStationSecretPicDesc1
    string Description2		AttrexianStationSecretPicDesc2
    string Description3		AttrexianStationSecretPicDesc3
    string RadarDescription		AttrexianStationSecretPicRadar
}

OBJECT StalkerSecretPic		Secret
{
    string InteractiveType		NonInteractive
    string Description1		StalkerSecretPicDesc1
    string Description2		StalkerSecretPicDesc2
    string Description3		StalkerSecretPicDesc3
    string RadarDescription		StalkerSecretPicRadar
}

OBJECT IdryllRuins2SecretPic		Secret
{
    string InteractiveType		NonInteractive
    string Description1		IdryllRuins2SecretPicDesc1
    string Description2		IdryllRuins2SecretPicDesc2
    string Description3		IdryllRuins2SecretPicDesc3
    string RadarDescription		IdryllRuins2SecretPicRadar
}

OBJECT AttrexianFemaleSecretPic		Secret
{
    string InteractiveType		NonInteractive
    string Description1		AttrexianFemaleSecretPicDesc1
    string Description2		AttrexianFemaleSecretPicDesc2
    string Description3		AttrexianFemaleSecretPicDesc3
    string RadarDescription		AttrexianFemaleSecretPicRadar
}

OBJECT CommanderSecretPic		Secret
{
    string InteractiveType		NonInteractive
    string Description1		CommanderSecretPicDesc1
    string Description2		CommanderSecretPicDesc2
    string Description3		CommanderSecretPicDesc3
    string RadarDescription		CommanderSecretPicRadar
}

OBJECT QuadrapedSecretPic		Secret
{
    string InteractiveType		NonInteractive
    string Description1		QuadrapedSecretPicDesc1
    string Description2		QuadrapedSecretPicDesc2
    string Description3		QuadrapedSecretPicDesc3
    string RadarDescription		QuadrapedSecretPicRadar
}

OBJECT AttrexianStationSecretPic2		Secret
{
    string InteractiveType		NonInteractive
    string Description1		AttrexianStationSecretPic2Desc1
    string Description2		AttrexianStationSecretPic2Desc2
    string Description3		AttrexianStationSecretPic2Desc3
    string RadarDescription		AttrexianStationSecretPic2Radar
}

OBJECT IdryllRuins1SecretPic		Secret
{
    string InteractiveType		NonInteractive
    string Description1		IdryllRuins1SecretPicDesc1
    string Description2		IdryllRuins1SecretPicDesc2
    string Description3		IdryllRuins1SecretPicDesc3
    string RadarDescription		IdryllRuins1SecretPicRadar
}

OBJECT AttrexianMaleSecretPic		Secret
{
    string InteractiveType		NonInteractive
    string Description1		AttrexianMaleSecretPicDesc1
    string Description2		AttrexianMaleSecretPicDesc2
    string Description3		AttrexianMaleSecretPicDesc3
    string RadarDescription		AttrexianMaleSecretPicRadar
}

OBJECT Archeopendrapic		Secret
{
    string InteractiveType		NonInteractive
    string Description1		ArcheopendraPicDesc1
    string Description2		ArcheopendraPicDesc2
    string Description3		ArcheopendraPicDesc3
    string RadarDescription		ArcheopendraPicRadar
}

OBJECT IMODpic		Secret
{
    string InteractiveType		NonInteractive
    string Description1		ImodPicDesc1
    string Description2		ImodPicDesc2
    string Description3		ImodPicDesc3
    string RadarDescription		ImodPicRadar
}

OBJECT FedRiflepic		Secret
{
    string InteractiveType		NonInteractive
    string Description1		FedRiflePicDesc1
    string Description2		FedRiflePicDesc2
    string Description3		FedRiflePicDesc3
    string RadarDescription		FedRiflePicRadar
}

OBJECT FadeOutSlow		DisplayEffects
{
    float AttachEffect		0
    float EffectTime		0
    float Immobilize		0
    float NumEffects		0
    float FadeTime		2.5
}

OBJECT FadeInSlow		DisplayEffects
{
    float AttachEffect		0
    float EffectTime		0
    float Immobilize		0
    float NumEffects		0
    float FadeTime		2.5
}

OBJECT StarfleetCadetMaleB		NPC
{
    string Description1		StarfleetCadetMaleBDesc1
    string Description2		StarfleetCadetMaleBDesc2
    string Description3		StarfleetCadetMaleBDesc3
    string InteractiveType		Friendly
    string RadarDescription		StarfleetCadetMaleBRadar
}

OBJECT StarfleetCadetMaleC		NPC
{
    string Description1		StarfleetCadetMaleCDesc1
    string Description2		StarfleetCadetMaleCDesc2
    string Description3		StarfleetCadetMaleCDesc3
    string InteractiveType		Friendly
    string RadarDescription		StarfleetCadetMaleCRadar
}

OBJECT StarfleetCadetMale2B		NPC
{
    string Description1		StarfleetCadetMale2BDesc1
    string Description2		StarfleetCadetMale2BDesc2
    string Description3		StarfleetCadetMale2BDesc3
    string InteractiveType		Friendly
    string RadarDescription		StarfleetCadetMale2BRadar
}

OBJECT StarfleetCadetMale4		NPC
{
    string Description1		StarfleetCadetMale4Desc1
    string Description2		StarfleetCadetMale4Desc2
    string Description3		StarfleetCadetMale4Desc3
    string InteractiveType		Friendly
    string RadarDescription		StarfleetCadetMale4Radar
}

OBJECT StarfleetCadetMale5		NPC
{
    string Description1		StarfleetCadetMale5Desc1
    string Description2		StarfleetCadetMale5Desc2
    string Description3		StarfleetCadetMale5Desc3
    string InteractiveType		Friendly
    string RadarDescription		StarfleetCadetMale5Radar
}

OBJECT StarfleetCadetMale3B		NPC
{
    string Description1		StarfleetCadetMale3BDesc1
    string Description2		StarfleetCadetMale3BDesc2
    string Description3		StarfleetCadetMale3BDesc3
    string InteractiveType		Friendly
    string RadarDescription		StarfleetCadetMale3BRadar
}

OBJECT StarfleetCadetFemale2B		NPC
{
    string Description1		StarfleetCadetFemale2BDesc1
    string Description2		StarfleetCadetFemale2BDesc2
    string Description3		StarfleetCadetFemale2BDesc3
    string InteractiveType		Friendly
    string RadarDescription		StarfleetCadetFemale2BRadar
}

OBJECT StarfleetCadetFemale2C		NPC
{
    string Description1		StarfleetCadetFemale2CDesc1
    string Description2		StarfleetCadetFemale2CDesc2
    string Description3		StarfleetCadetFemale2CDesc3
    string InteractiveType		Friendly
    string RadarDescription		StarfleetCadetFemale2CRadar
}

OBJECT StarfleetCadetFemale3B		NPC
{
    string Description1		StarfleetCadetFemale3BDesc1
    string Description2		StarfleetCadetFemale3BDesc2
    string Description3		StarfleetCadetFemale3BDesc3
    string InteractiveType		Friendly
    string RadarDescription		StarfleetCadetFemale3BRadar
}

OBJECT StarfleetCadetFemale4		NPC
{
}

OBJECT StarfleetCadetFemale5		NPC
{
}

OBJECT StarfleetCadetFemaleB		NPC
{
    string Description1		StarfleetCadetFemaleBDesc1
    string Description2		StarfleetCadetFemaleBDesc2
    string Description3		StarfleetCadetFemaleBDesc3
    string InteractiveType		Friendly
    string RadarDescription		StarfleetCadetFemaleBRadar
}

OBJECT StarfleetMale2Dallas		NPC
{
    string Description1		StarfleetMale2DallasDesc1
    string Description2		StarfleetMale2DallasDesc2
    string Description3		StarfleetMale2DallasDesc3
    string InteractiveType		Friendly
    string RadarDescription		StarfleetMale2DallasRadar
}

OBJECT IMOD		Weapons
{
}

OBJECT Tricorder		Weapons
{
    string Description1		TricorderDesc1
    string Description2		TricorderDesc2
    string Description3		TricorderDesc3
    string InteractiveType		Usable
    string RadarDescription		TricorderRadar
}

OBJECT IdryllStaff		Weapons
{
    string Description1		IdryllStaffDesc1
    string Description2		IdryllStaffDesc2
    string Description3		IdryllStaffDesc3
    string InteractiveType		Usable
    string RadarDescription		IdryllStaffRadar
}

OBJECT TransportOutRomulan		DisplayEffects
{
    float AnimName		1
    string EffectName		fx/fx-beamsparkle-romulan.tik
    string EffectPosName		centroid
    float EffectTime		1.25
    string ShaderName		transport-romulan
    string SoundName		snd_bodytransportout
    float TransportTime		1.25
}

OBJECT RomulanGenericUsableConsole		RomulanEnvironment
{
    string Description1		RomulanGenericUsableConsoleDesc1
    string Description2		RomulanGenericUsableConsoleDesc2
    string Description3		RomulanGenericUsableConsoleDesc3
    string InteractiveType		Usable
}

OBJECT StarfleetMale7		NPC
{
    string Description1		StarfleetMale7Desc1
    string Description2		StarfleetMale7Desc2
    string Description3		StarfleetMale7Desc3
    string InteractiveType		Friendly
    float visiondistance		1200
    float health		1000
    float fov		360
    string RadarDescription		StarfleetMale7Radar
}

OBJECT StarfleetFemale7		NPC
{
    string Description1		StarfleetFemale7Desc1
    string Description2		StarfleetFemale7Desc2
    string Description3		StarfleetFemaleDesc3
    string InteractiveType		Friendly
    string RadarDescription		StarfleetFemale7Radar
    float fov		360
    float health		1000
    float visiondistance		1200
}

OBJECT Background		UI
{
    float ShowShip		1
}

OBJECT TransportOutRomulanCinematic		DisplayEffects
{
    float AnimName		1
    string EffectName		fx/fx-beamsparkle-romulan.tik
    string EffectPosName		centroid
    float EffectTime		1.25
    string ShaderName		transport-romulan
    float SoundName		1
    float TransportTime		1.25
}


//[b60013] chrissstrahl - coop global archetype
OBJECT FFScanable		GlobalEnvironments
{
    string InteractiveType		TricorderUsable
	string Description1			FFScanableDesc1
	string Description2			FFScanableDesc2
	string RadarDescription		FFScanableRadar
}

//coop mod archetypes
OBJECT UseSecurity		GlobalEnvironments
{
    string InteractiveType		Usable
	string Description1			UseSecurityDesc1
	string Description2			UseSecurityDesc2
	string RadarDescription		UseSecurityRadar
}
OBJECT Use		GlobalEnvironments
{
    string InteractiveType			Usable
	string Description1			UseDesc1
	string Description2			UseDesc2
	string RadarDescription		UseRadar
}
OBJECT Hostile		GlobalEnvironments
{
    string InteractiveType			Enemy
	string Description1			HostileDesc1
	string Description2			HostileDesc2
	string RadarDescription		HostileRadar
}
OBJECT Friend		GlobalEnvironments
{
    string InteractiveType		Friendly
	string Description1			FriendDesc1
	string Description2			FriendDesc2
	string RadarDescription		FriendRadar
}
OBJECT Team		GlobalEnvironments
{
    string InteractiveType		Teammate
	string Description1			TeamDesc1
	string Description2			TeamDesc2
	string RadarDescription		TeamRadar
}
OBJECT Scan		GlobalEnvironments
{
    string InteractiveType		TricorderUsable
	string Description1		ScanDesc1
	string Description2		ScanDesc2
	string RadarDescription		ScanRadar
}
OBJECT Destroy		GlobalEnvironments
{
    string InteractiveType	Destructable
	string Description1		DestroyDesc1
	string Description2		DestroyDesc2
	string RadarDescription		DestroyRadar
}


