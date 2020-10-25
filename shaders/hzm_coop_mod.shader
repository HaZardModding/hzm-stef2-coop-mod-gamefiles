//type 8 shuttle shader by Deadlydarkness
models/vehicle/type8/t8nac
{
	qer_editorimage models/vehicle/type8/t8nac.tga
if novertexlight
	{
		map textures/env/env_metal2.tga
		rgbGen default
		tcGen environment
		tcMod scale 2 2
	}
	{
		map models/vehicle/type8/t8nac.tga
		rgbGen default
		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
	}
	{
		map models/vehicle/type8/t8nac_glow.tga
		blendfunc add
		rgbGen wave sin 0.75 0.1 0 0.3
	}
endif
if vertexlight
	{
		map models/vehicle/type8/t8nac_glow.tga
		rgbGen default
	}
endif
}

models/vehicle/type8/t8body
{
	qer_editorimage models/vehicle/type8/t8body.tga
if novertexlight
	{
		map textures/env/env_metal2.tga
		rgbGen default
		tcGen environment
		tcMod scale 1 1
	}
	{
		map models/vehicle/type8/t8body.tga
		rgbGen default
		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
	}
	{
		map models/vehicle/type8/t8body_glow.tga
		blendfunc add
		rgbGen wave sin 0.75 0.1 0 0.3
	}
endif
if vertexlight
	{
		map models/vehicle/type8/t8body_glow.tga
		rgbGen default
	}
endif
}

models/vehicle/type8/reg01
{
	surfaceparm trans
	surfaceparm playerclip
	surfaceparm monsterclip
	cull none
	nopicmip
	qer_editorimage models/vehicle/type8/reg01.tga
 
   	{
		map models/vehicle/type8/reg01.tga
		blendFunc blend
		alphaFunc GT0
		depthWrite
		rgbGen identity
	}
	{
		map $lightmap
		rgbGen identity
		blendFunc GL_DST_COLOR GL_ZERO
		depthFunc equal
	}
}

models/vehicle/type8/reg02
{
	surfaceparm trans
	surfaceparm playerclip
	surfaceparm monsterclip
	cull none
	nopicmip
	qer_editorimage models/vehicle/type8/reg02.tga
 
   	{
		map models/vehicle/type8/reg02.tga
		blendFunc blend
		alphaFunc GT0
		depthWrite
		rgbGen identity
	}
	{
		map $lightmap
		rgbGen identity
		blendFunc GL_DST_COLOR GL_ZERO
		depthFunc equal
	}
}

models/vehicle/type8/noreg
{
	surfaceparm trans
	surfaceparm playerclip
	surfaceparm monsterclip
	cull none
	nopicmip
	qer_editorimage models/vehicle/type8/noreg.tga
 
   	{
		map models/vehicle/type8/noreg.tga
		blendFunc blend
		alphaFunc GT0
		depthWrite
		rgbGen identity
	}
	{
		map $lightmap
		rgbGen identity
		blendFunc GL_DST_COLOR GL_ZERO
		depthFunc equal
	}
}


//--------------------------------------------------------------------
//Made/Edited by Explorer
//explorer-studios@mail.com
//taken from star trek voyager conflict of intrests
//--------------------------------------------------------------------
//
textures/coop_mod/warp01
{
	qer_editorimage textures/coop_mod/warp01.tga
	surfaceparm nonsolid
	surfaceparm playerclip
	surfaceparm trans
	surfaceparm monsterclip
	cull disable
	nopicmip
	{
		map textures/coop_mod/warp01.tga
		blendfunc gl_src_alpha gl_dst_alpha
		rgbGen identity
		tcMod scroll 1 0
		depthWrite
		alphaFunc GT0
	}
}
//--------------------------------------------------------------------
//Made/Edited by Explorer
//explorer-studios@mail.com
//taken from star trek voyager conflict of intrests
//--------------------------------------------------------------------
textures/coop_mod/warp02
{
	qer_editorimage textures/coop_mod/warp02.tga
	surfaceparm nonsolid
	surfaceparm playerclip
	surfaceparm trans
	surfaceparm monsterclip
	cull disable
	nopicmip
	{
		map textures/coop_mod/warp02.tga
		blendfunc gl_src_alpha gl_dst_alpha
		rgbGen identity
		tcMod scroll 1 0
		depthWrite
		alphaFunc GT0
	}
}
//--------------------------------------------------------------------
//Made/Edited by Explorer
//explorer-studios@mail.com
//taken from star trek voyager conflict of intrests
//--------------------------------------------------------------------
textures/coop_mod/warp03
{
	qer_editorimage textures/coop_mod/warp03.tga
	surfaceparm nonsolid
	surfaceparm playerclip
	surfaceparm trans
	surfaceparm monsterclip
	cull disable
	nopicmip
	{
		map textures/coop_mod/warp03.tga
		blendfunc gl_src_alpha gl_dst_alpha
		rgbGen identity
		tcMod scroll 1 0
		depthWrite
		alphaFunc GT0
	}
}


//--------------------------------------------------------------------
// EFFECT ICED
//--------------------------------------------------------------------
coop_iceing
{
	nomipmaps
	nopicmip
	cull none
	{
		clampmap textures/coop_mod/iced.tga
		blendfunc blend
		alphaFunc GT0
		alphaGen global
	}
}

//--------------------------------------------------------------------
coop_objective
{
   nomipmaps
   nopicmip
   cull none
   {
      clampmap sysimg/hud/coop_7.tga
      Blendfunc Blend
      alphafunc GT0
      alphaGen global
      rgbGen global
	 rgbGen wave sin 0.85 0.25 0 0.225
   }
}

//--------------------------------------------------------------------
coop_Technician
{
   nomipmaps
   nopicmip
   cull none
   {
		map sysimg/hud/coop_3.tga
		blendfunc blend
		alphaFunc GT0
		alphaGen global
   }
}
//--------------------------------------------------------------------
coop_Medic
{
   nomipmaps
   nopicmip
   cull none
   {
		map sysimg/hud/coop_1.tga
		blendfunc blend
		alphaFunc GT0
		alphaGen global
   }
}
//--------------------------------------------------------------------
coop_HeavyWeapons
{
   nomipmaps
   nopicmip
   cull none
   {
		map sysimg/hud/coop_2.tga
		blendfunc blend
		alphaFunc GT0
		alphaGen global
   }
}
//--------------------------------------------------------------------
coop_story
{
   nomipmaps
   nopicmip
   cull none
   {
		map sysimg/hud/coop_4.tga
		blendfunc blend
		alphaFunc GT0
		alphaGen global
   }
}

//--------------------------------------------------------------------
// Advanced Mint Health Hud
//--------------------------------------------------------------------
hud/advanced_mint_health_hud
{
	nomipmaps
	nopicmip
	cull none
	{
		map sysimg/hud/hud_health_v2green_bg.tga
		blendfunc blend
		alphaFunc GT0
		alphaGen global
		rgbGen wave sin 0.85 0.25 0 0.425
	}
}
//--------------------------------------------------------------------
// server is loading hud
//--------------------------------------------------------------------
coop_loading
{
   nomipmaps
   nopicmip
   cull none
   {
		map sysimg/hud/coop_9.tga
		blendfunc blend
		alphaFunc GT0
		alphaGen global
		rgbGen wave sin 0.85 0.25 0 1
   }
}

//--------------------------------------------------------------------
// Radar Hud
//--------------------------------------------------------------------
coop_hud_radarBg
{
	//nomipmaps
	nopicmip
   cull none
	{
		map sysimg/hud/radar/basic-ground-plane.tga
		blendfunc blend
		alphaFunc GT0
		alphaGen global
	}		
}
//--------------------------------------------------------------------
// Blank/empty
//--------------------------------------------------------------------
coop_empty
{
	//nomipmaps
	nopicmip
   cull none
	{
		map sysimg/hud/radar/basic-ground-plane.tga
		blendfunc blend
		alphaFunc GT0
		alphaGen global
	}		
}


