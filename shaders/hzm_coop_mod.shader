textures/coop_mod/pac/healarea
{
	qer_editorimage textures/coop_mod/pac/healarea.tga
	surfaceparm nonsolid
	surfaceparm trans
	cull disable
	nopicmip
	{
		clampmap textures/coop_mod/pac/healarea.tga
		blendfunc blend
		alphaFunc GT0
		//rgbGen wave sin 0.85 0.25 0.5 3
	}
}

textures/coop_mod/pac/invalid
{
	qer_editorimage sysimg/icons/mp/elimination_eliminated.tga
	surfaceparm nonsolid
	surfaceparm trans
	cull disable
	nopicmip
	{
		clampmap sysimg/icons/mp/elimination_eliminated.tga
		blendfunc blend
		alphaFunc GT0
		//rgbGen wave sin 0.85 0.25 0.5 3
	}
}

textures/coop_mod/pac/mindmeld
{
	qer_editorimage textures/coop_mod/pac/mindmeld.tga
	surfaceparm nonsolid
	surfaceparm trans
	cull disable
	nopicmip
	{
		clampmap textures/coop_mod/pac/mindmeld.tga
		blendfunc blend
		alphaFunc GT0
		//rgbGen wave sin 0.85 0.25 0.5 3
	}
}

textures/coop_mod/pac/awayteam
{
	qer_editorimage textures/coop_mod/pac/awayteam.tga
	surfaceparm nonsolid
	surfaceparm trans
	cull disable
	nopicmip
	{
		clampmap textures/coop_mod/pac/awayteam.tga
		blendfunc blend
		alphaFunc GT0
		//rgbGen wave sin 0.85 0.25 0.5 3
	}
}

textures/coop_mod/pac/orbitalstrike
{
	qer_editorimage textures/coop_mod/pac/orbitalstrike.tga
	surfaceparm nonsolid
	surfaceparm trans
	cull disable
	nopicmip
	{
		clampmap textures/coop_mod/pac/orbitalstrike.tga
		blendfunc blend
		alphaFunc GT0
		//rgbGen wave sin 0.85 0.25 0.5 3
	}
}


textures/coop_mod/nature/vine

{
	surfaceparm trans
	surfaceparm playerclip
	surfaceparm monsterclip
	//cull none
	//nopicmip
	qer_editorimage textures/coop_mod/nature/vine.tga
   	{
		map textures/coop_mod/nature/vine.tga
		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
		alphaFunc GE128
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

//--------------------------------------------------------------------
coop_pulse
//--------------------------------------------------------------------
{
   cull none
	{
		clampmap sysimg/hud/radar/ground-plane-pulse.tga
		blendFunc ADD
		alphaFunc GT0
		rgbGen wave sin 0.0 1.0 1.0 0.5
		tcMod stretch sin 1.0 2.75 0.0 0.5
	}
}

//textures/coop_bugs/s0
coop_peBlinking
{
   nomipmaps
   nopicmip
   cull none
   {
		map sysimg/hud/coop_11.tga
		blendfunc blend
		alphaFunc GT0
		alphaGen global
		//-,-,mentode,base,amplitude,phase,frequency
		rgbGen wave square 1 1 0.5 0.25
   }
}

coop_bugs-data-btn-bg
{
   nomipmaps
   nopicmip
   cull none
   {
		map textures/coop_bugs/2.tga
		blendfunc blend
		alphaFunc GT0
		alphaGen global
   }
}

pattern-enhancer-laser
{
cull none
  {
  clampmap textures/coop_bugs/14.tga
  blendFunc GL_ONE GL_ONE
  tcMod scroll -0.5 0
  tcMod scale 4 1
  rgbGen wave Sin 1 0.2 10 2.5
  }
}

//--------------------------------------------------------------------
// Blood Sprite Shader for the Blod Model
//--------------------------------------------------------------------
zombi_blood-red
{
   spritegen parallel_oriented
      {
      map models/fx/blood/bloodmap1.tga
      blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
      alphaGen vertex
      rgbgen vertex
      }
}

//--------------------------------------------------------------------
// Blood Sprite Shader for the Blod Model
//--------------------------------------------------------------------
zombi_blood-green
{
	spritegen parallel_oriented
		{
		map models/fx/blood/greenblood1.tga
		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
		alphaGen vertex
		rgbgen vertex
		}
}


