//SHADERs FOR coop_hatoriaOutpost
textures/coop_hatoriaOutpost/fedPoolReflections
{
	surfaceparm nodamage
	surfaceparm noimpact
	surfaceparm nonsolid
	surfaceparm nolightmap
    surfaceparm trans
	qer_editorimage textures/starfleet/sfwater1.tga
  	{
        animmap 15 textures/shaderfx/caus001.tga textures/shaderfx/caus002.tga textures/shaderfx/caus003.tga textures/shaderfx/caus004.tga textures/shaderfx/caus005.tga textures/shaderfx/caus006.tga textures/shaderfx/caus007.tga textures/shaderfx/caus008.tga textures/shaderfx/caus009.tga textures/shaderfx/caus010.tga textures/shaderfx/caus011.tga textures/shaderfx/caus012.tga textures/shaderfx/caus013.tga textures/shaderfx/caus014.tga textures/shaderfx/caus015.tga textures/shaderfx/caus016.tga textures/shaderfx/caus017.tga textures/shaderfx/caus018.tga textures/shaderfx/caus019.tga textures/shaderfx/caus020.tga textures/shaderfx/caus021.tga textures/shaderfx/caus022.tga textures/shaderfx/caus023.tga textures/shaderfx/caus024.tga textures/shaderfx/caus025.tga textures/shaderfx/caus026.tga textures/shaderfx/caus027.tga textures/shaderfx/caus028.tga textures/shaderfx/caus029.tga textures/shaderfx/caus030.tga textures/shaderfx/caus031.tga textures/shaderfx/caus032.tga textures/shaderfx/caus033.tga textures/shaderfx/caus034.tga textures/shaderfx/caus035.tga textures/shaderfx/caus036.tga textures/shaderfx/caus037.tga textures/shaderfx/caus038.tga textures/shaderfx/caus039.tga textures/shaderfx/caus040.tga textures/shaderfx/caus041.tga textures/shaderfx/caus042.tga textures/shaderfx/caus043.tga textures/shaderfx/caus044.tga textures/shaderfx/caus045.tga textures/shaderfx/caus046.tga textures/shaderfx/caus047.tga
		blendFunc add                                                                    
		depthWrite   
		tcMod scale 0.8 0.8
		rgbGen constant 0.0 0.35 0.9
   	}
}

//-------------------------------------------------------
// Damages Effect on Hull...
//-------------------------------------------------------
textures/coop_hatoriaOutpost/effect_damaged
{
surfaceparm nonsolid
surfaceparm nolightmap
surfaceparm trans
nomipmaps
nopicmip
cull none
	qer_editorimage textures/coop_hatoriaOutpost/effect_damaged.tga
	{
		map textures/coop_hatoriaOutpost/effect_damaged.tga
		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
		//rgbGen wave sin 0.85 0.25 0 0.425
		rgbGen identity
	}
}


//-------------------------------------------------------
// Used instad of clip all, with nodamage flag
//-------------------------------------------------------
textures/coop_hatoriaOutpost/shuttle_clip
{
	surfaceparm nodamage
	surfaceparm nodraw
	qer_editorimage textures/coop_hatoriaOutpost/shuttle-clip.tga
}




