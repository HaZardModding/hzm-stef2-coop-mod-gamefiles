

//---------------------------------------------------------
state START
//---------------------------------------------------------
{
	entrycommands
	{
		groupattack 1
		runthread IdryllFloatAway
	}
}

//void IdryllFloatAway()
//{
//	entity e;
//	vector o;
//	float deathanim;
//	
//	deathanim = randomint( 2 );
//	
//	e = getcurrententity();
//	if( doesEntityExist( e ) )
//	{
//		e.attackplayer();
//		wait( 0.05 );
//		e.groupattack( 1 );
//		e.ai_off();
//		
//		if( deathanim == 1 )
//			e.anim( "death_A" );
//		else
//			e.anim( "death_B" );
//		
//		e.notsolid();
//		e.gravity( 0 );
//		o = e.getorigin();
//		o_z += 2;
//		e.origin( o );
//		wait( 0.05 );
//		e.setvelocity( '0 0 64' );
//		
//		if( deathanim == 1 )
//		{
//			waitforanimation( e, "death_A" );
//			e.anim( "death_A_idle" );
//		}
//		else
//		{
//			waitforanimation( e, "death_B" );
//			e.anim( "death_B_idle" );
//		}
//					
//		wait( 1 + randomfloat( 3 ) );
//		
//		e.displayeffect( "TransportOut", "Idryll" );
//		wait( 2 );
//		e.suicide();
//		e.remove();
//	}
//}
