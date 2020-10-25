//--------------------------------------------------------------------
// coop_gbsCredits
//--------------------------------------------------------------------
textures/coop_mod/misc/chrissstrahl
{
    qer_editorimage textures/coop_mod/misc/chrissstrahl0.tga
    {
        map $lightmap
    }
    {
        animMap 0.2 textures/coop_mod/misc/chrissstrahl0.tga textures/coop_mod/misc/chrissstrahl1.tga textures/coop_mod/misc/chrissstrahl2.tga textures/coop_mod/misc/chrissstrahl3.tga textures/coop_mod/misc/chrissstrahl4.tga textures/coop_mod/misc/chrissstrahl5.tga textures/coop_mod/misc/chrissstrahl6.tga
        blendFunc GL_DST_COLOR GL_ZERO
    }
}

//patched FF
textures/coop_gbs/gbs_ffblue
{
surfaceparm trans
surfaceparm nolightmap
tessSize 32
sort nearest
qer_editorimage textures/shaderfx/forcefieldblue.tga
	{
		map textures/shaderfx/forcefieldblue.tga
		blendfunc GL_src_alpha GL_one
		alphaFunc GT0
		tcmod scroll 0.5 1.5
		tcMod turb 1 2 0.115 2.64
		tcmod scale 2 2
	       	alphaGen oneMinusDot 0.25 1.0
	       	//depthWrite
	}	
	{
		map textures/shaderfx/forcefieldblue02.tga
		blendfunc GL_src_alpha GL_one
		alphaFunc GT0
		tcmod scroll 78.654 -1.0
		tcmod scale 2 2
		rgbGen wave sin 0.75 0.5 0.031 0.2
	        alphaGen dot 1.0 0.25
		detail
	}
	{
		map textures/shaderfx/forcefieldblue03.tga
		blendfunc GL_src_alpha GL_one
		alphaFunc GT0
		tcMod turb 0 1 0.115 1.835
		rgbGen wave sin 0.75 0.5 0.25 0.25
	        alphaGen oneMinusDot 0.15 1.0
		detail
	}
	{
		map textures/shaderfx/fflinefx02.tga
		blendfunc GL_src_alpha GL_one
		alphaFunc GT0
		rgbGen wave sin 0 0.8 0.031 0.3
		tcmod stretch sin 1.6 1 0 1
		tcmod scroll 1 .8
		tcmod scale .025 1
		detail
	}
	
}


//                E SHUTTLE EXTERIOR
gbs_shuttle
{
	qer_editorimage models/vehicle/e-shuttle/e-shuttle-base.tga
if novertexlight
	{
		map textures/env/env_metal2.tga
		rgbGen default
		tcGen environment
		tcMod scale 4 4
	}
	{
		map models/vehicle/e-shuttle/e-shuttle-base.tga
		rgbGen default
		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
	}
endif
if vertexlight
	{
		map models/vehicle/e-shuttle/e-shuttle-base.tga
		rgbGen default
	}
endif
}


textures/coop_gbs/gbs_general/hallway_redalert
{
	qer_editorimage textures/enterprise/hallwaypanel_piece3r.tga
	{
		map textures/enterprise/hallwaypanel_piece3.tga
	}
	{
		map $lightmap
		blendfunc gl_dst_color gl_zero
		rgbGen identity
	}
	{
		map textures/shaderfx/hallwaypanel_piece3rglow.tga
		blendfunc GL_ONE GL_ONE
		rgbGen wave sin 0.0 1 0 0.4
	}
}

gbs_ac-skylayer2-cloudstar
{
qer_editorimage models/sky/textures/ac-bg.tga
surfaceparm nolightmap
surfaceparm trans
	{
		map models/sky/textures/stars-large.tga
		tcMod scale 20 20
	}
	{
		map models/sky/gbs_cloudystars/ac-clouds2.tga
		blendFunc blend
		tcMod scroll .008 .003
		tcMod scale 4 4
	}
	{
		map models/sky/gbs_cloudystars/ac-clouds.tga
		blendFunc blend
		tcMod scroll .0025 0
		tcMod scale 4 4
	}
}

textures/coop_gbs/map2flcarssec
{	

	qer_editorimage textures/coop_gbs/map2/flcarssecurity.tga	
	nopicmip
	nomipmaps

	{
			map textures/coop_gbs/map2/flcarssecurity.tga	
	}
	{
			map textures/coop_gbs/map2/flcarssecurity.tga 
			blendfunc add
			rgbGen wave sin 0.4 0.3 0 1	
	}
	{
			map $lightmap
			blendFunc GL_DST_COLOR GL_ZERO
	}
}

textures/coop_gbs/map2bluefog2
{
	surfaceparm nonsolid
	surfaceparm noimpact
	surfaceparm nomarks
    	surfaceparm nolightmap
	{
		map models/weapons/attrexian_rifle/viewmodel/attrex-gas.tga
		blendFunc GL_ONE GL_ONE
		alphaGen vertex
		rgbGen vertex
	}
}

textures/coop_gbs/map2bluefog
{
	qer_editorimage models/weapons/attrexian_rifle/viewmodel/attrex-gas.tga
	surfaceparm nosteps
	surfaceparm nonsolid
	surfaceparm noimpact
	surfaceparm nomarks
    	surfaceparm nolightmap
	surfaceparm trans
	{
		map models/weapons/attrexian_rifle/viewmodel/attrex-gas.tga
		blendfunc add
		//rgbGen vertex
		tcMod scale .2 .2
		tcMod scroll 0.1 0.01
		detail
	}
	{
		map models/weapons/attrexian_rifle/viewmodel/attrex-gas.tga
		blendfunc add
		//rgbGen vertex
		tcMod scale .2 .2
		tcMod scroll -0.01 -0.1
		detail
	}

}

gbs_bluegas
{
	spritegen oriented
	sort additive
	{
		map models/weapons/attrexian_rifle/viewmodel/attrex-gas.tga
		blendFunc GL_ONE GL_ONE
		alphaGen vertex
		rgbGen vertex
	}
}


textures/coop_gbs/akq_qonos/sky_qonos
{
    q3map_lightimage textures/holodeck_temple/lightcyan.tga
    qer_editorimage textures/common/sky.tga
    q3map_surfacelight 200
    q3map_lightsubdivide 256
    surfaceparm noimpact
    surfaceparm nomarks
    surfaceparm nolightmap
    surfaceparm sky
    q3map_sun 1 1 1 175 65 45
    skyParms env/stars 512 -
    {
        map textures/holodeck_temple/clouds.tga
        blendFunc GL_ONE GL_ONE
        tcMod scale 4 4
        tcMod scroll 0.015 0.01
    }
    {
        map textures/holodeck_temple/clouds2.tga
        blendFunc GL_DST_COLOR GL_SRC_COLOR
        tcMod scale 3 3
        tcMod scroll 0.035 0.025
    }
}

textures/coop_gbs/akq_qonos/light_wall
{
    qer_editorimage textures/coop_gbs/akq_sfx/primaryhall_light.tga
    q3map_surfacelight 30000
    surfaceparm nolightmap
    {
        map textures/coop_gbs/akq_sfx/primaryhall_light.tga
    }
}

textures/coop_gbs/akq_qonos/light_wall2
{
    qer_editorimage textures/coop_gbs/akq_sfx/primaryhall_light.tga
    q3map_surfacelight 100
    surfaceparm nolightmap
    {
        map textures/coop_gbs/akq_sfx/primaryhall_light.tga
    }
}


textures/coop_gbs/akq_qonos/window_01
{
    qer_editorimage textures/coop_gbs/akq_sfx/window_01.tga
    q3map_surfacelight 1200
    surfaceparm nolightmap
    surfaceparm trans
    {
        map textures/coop_gbs/akq_sfx/window_01.tga
        blendFunc GL_ONE GL_ONE
        tcGen environment
        tcMod scale 6 6
    }
}

textures/coop_gbs/akq_qonos/window_grawl
{
    qer_editorimage textures/coop_gbs/akq_sfx/window_grawl.tga
    q3map_surfacelight 1200
    surfaceparm nolightmap
    {
        map textures/coop_gbs/akq_sfx/window_grawl.tga
    }
}

textures/coop_gbs/akq_qonos/klingon_forcefield
{
    qer_editorimage textures/coop_gbs/akq_sfx/red_field.tga
    surfaceparm nomarks
    surfaceparm nolightmap
    surfaceparm trans
    cull disable
    {
        map textures/coop_gbs/akq_sfx/red_field.tga
        blendFunc GL_ONE GL_ONE
        tcMod scroll 1292.7 1133.9
    }
}

textures/coop_gbs/akq_qonos/fire_qonos1
{
    qer_editorimage textures/coop_gbs/akq_sfx/flame1.tga
    surfaceparm nolightmap
    cull disable
    {
        animMap 10 textures/coop_gbs/akq_sfx/flame1.tga textures/coop_gbs/akq_sfx/flame2.tga textures/coop_gbs/akq_sfx/flame3.tga textures/coop_gbs/akq_sfx/flame4.tga textures/coop_gbs/akq_sfx/flame5.tga textures/coop_gbs/akq_sfx/flame6.tga textures/coop_gbs/akq_sfx/flame7.tga textures/coop_gbs/akq_sfx/flame8.tga 
        blendFunc GL_ONE GL_SRC_ALPHA
    }
}

textures/coop_gbs/akq_qonos/fire_qonos2
{
    qer_editorimage textures/coop_gbs/akq_sfx/flame1.tga
    q3map_surfacelight 500
    surfaceparm nomarks
    surfaceparm nolightmap
    surfaceparm nonsolid
    surfaceparm trans
    cull disable
    {
        animMap 10 textures/coop_gbs/akq_sfx/flame1.tga textures/coop_gbs/akq_sfx/flame2.tga textures/coop_gbs/akq_sfx/flame3.tga textures/coop_gbs/akq_sfx/flame4.tga textures/coop_gbs/akq_sfx/flame5.tga textures/coop_gbs/akq_sfx/flame6.tga textures/coop_gbs/akq_sfx/flame7.tga textures/coop_gbs/akq_sfx/flame8.tga 
        blendFunc GL_ONE GL_ONE
        rgbGen wave inversesawtooth 0 1 0 10
    }
    {
        animMap 10 textures/coop_gbs/akq_sfx/flame2.tga textures/coop_gbs/akq_sfx/flame3.tga textures/coop_gbs/akq_sfx/flame4.tga textures/coop_gbs/akq_sfx/flame5.tga textures/coop_gbs/akq_sfx/flame6.tga textures/coop_gbs/akq_sfx/flame7.tga textures/coop_gbs/akq_sfx/flame8.tga textures/coop_gbs/akq_sfx/flame1.tga 
        blendFunc GL_ONE GL_ONE
        rgbGen wave sawtooth 0 1 0 10
    }
    {
        map textures/coop_gbs/akq_sfx/flameball.tga
        blendFunc GL_ONE GL_ONE
        rgbGen wave sin 0.6 0.2 0 0.6
    }
}

textures/coop_gbs/akq_qonos/k_flag01
{
    qer_editorimage textures/coop_gbs/akq_sfx/k_flag01.tga
    surfaceparm nomarks
    cull disable
    deformVertexes wave 194 sin 0 3 0 0.4
    tessSize 64
    {
        map textures/coop_gbs/akq_sfx/k_flag01.tga
        rgbGen identity
    }
    {
        map textures/coop_gbs/akq_sfx/k_flag01.tga
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
        rgbGen identity
    }
    {
        //blendFunc GL_ONE GL_ONE
        map textures/coop_gbs/akq_sfx/shadow.tga
        blendFunc GL_DST_COLOR GL_ZERO
        rgbGen identity
        tcGen environment
    }
}

textures/coop_gbs/akq_qonos/beam_court
{
    qer_editorimage textures/borg/beam_edimage.tga
    qer_trans 0.5
    surfaceparm noimpact
    surfaceparm nolightmap
    surfaceparm nonsolid
    surfaceparm trans
    cull back
    {
        map textures/coop_gbs/akq_sfx/beam.tga
        alphaFunc GT0
        blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
        tcMod scroll -0.025 0
    }
    {
        map textures/borg/dust.tga
        blendFunc GL_ONE_MINUS_DST_COLOR GL_ONE_MINUS_SRC_COLOR
        tcMod scroll 0.05 0
    }
    {
        map textures/borg/dust.tga
        blendFunc GL_ONE_MINUS_DST_COLOR GL_ONE_MINUS_SRC_COLOR
        detail
        tcMod scroll -0.03 0
    }
}

textures/coop_gbs/gbs_zoo/flix0
{
    qer_editorimage textures/coop_gbs/GBS_Zoo/flix0.tga
    {
        map $lightmap
    }
    {
        animMap 0.5 textures/coop_gbs/gbs_zoo/flix0.tga textures/coop_gbs/gbs_zoo/flix1.tga textures/coop_gbs/gbs_zoo/flix2.tga textures/coop_gbs/gbs_zoo/flix3.tga textures/coop_gbs/gbs_zoo/flix4.tga textures/coop_gbs/gbs_zoo/flix5.tga textures/coop_gbs/gbs_zoo/flix6.tga textures/coop_gbs/gbs_zoo/flix7.tga textures/coop_gbs/gbs_zoo/flix8.tga 
        blendFunc GL_DST_COLOR GL_ZERO
    }
}

textures/coop_gbs/gbs_zoo/ltiefland0
{
    qer_editorimage textures/coop_gbs/GBS_Zoo/ltiefland0.tga
    {
        map $lightmap
    }
    {
        animMap 0.5 textures/coop_gbs/gbs_zoo/ltiefland0.tga textures/coop_gbs/gbs_zoo/ltiefland1.tga textures/coop_gbs/gbs_zoo/ltiefland2.tga textures/coop_gbs/gbs_zoo/ltiefland3.tga textures/coop_gbs/gbs_zoo/ltiefland4.tga textures/coop_gbs/gbs_zoo/ltiefland5.tga textures/coop_gbs/gbs_zoo/ltiefland6.tga textures/coop_gbs/gbs_zoo/ltiefland7.tga 
        blendFunc GL_DST_COLOR GL_ZERO
    }
}

textures/coop_gbs/gbs_zoo/markk0
{
    qer_editorimage textures/coop_gbs/GBS_Zoo/markk0.tga
    {
        map $lightmap
    }
    {
        animMap 0.5 textures/coop_gbs/gbs_zoo/markk0.tga textures/coop_gbs/gbs_zoo/markk1.tga textures/coop_gbs/gbs_zoo/markk2.tga textures/coop_gbs/gbs_zoo/markk3.tga textures/coop_gbs/gbs_zoo/markk4.tga textures/coop_gbs/gbs_zoo/maren0.tga textures/coop_gbs/gbs_zoo/maren1.tga textures/coop_gbs/gbs_zoo/maren2.tga textures/coop_gbs/gbs_zoo/maren3.tga textures/coop_gbs/gbs_zoo/maren4.tga 
        blendFunc GL_DST_COLOR GL_ZERO
    }
}

textures/coop_gbs/gbs_zoo/trekkie0
{
    qer_editorimage textures/coop_gbs/GBS_Zoo/trekkie0.tga
    {
        map $lightmap
    }
    {
        animMap 0.5 textures/coop_gbs/gbs_zoo/trekkie0.tga textures/coop_gbs/gbs_zoo/trekkie1.tga textures/coop_gbs/gbs_zoo/trekkie2.tga textures/coop_gbs/gbs_zoo/trekkie3.tga textures/coop_gbs/gbs_zoo/trekkie4.tga textures/coop_gbs/gbs_zoo/manuel0.tga textures/coop_gbs/gbs_zoo/manuel1.tga textures/coop_gbs/gbs_zoo/manuel2.tga textures/coop_gbs/gbs_zoo/manuel3.tga textures/coop_gbs/gbs_zoo/manuel4.tga 
        blendFunc GL_DST_COLOR GL_ZERO
    }
}

textures/coop_gbs/gbs_zoo/marc_haendel0
{
    qer_editorimage textures/coop_gbs/GBS_Zoo/marc_haendel0.tga
    {
        map $lightmap
    }
    {
        animMap 0.5 textures/coop_gbs/gbs_zoo/marc_haendel0.tga textures/coop_gbs/gbs_zoo/marc_haendel1.tga textures/coop_gbs/gbs_zoo/marc_haendel2.tga textures/coop_gbs/gbs_zoo/marc_haendel3.tga textures/coop_gbs/gbs_zoo/marc_haendel4.tga textures/coop_gbs/gbs_zoo/Falk0.tga textures/coop_gbs/gbs_zoo/Falk1.tga textures/coop_gbs/gbs_zoo/Falk2.tga textures/coop_gbs/gbs_zoo/Falk3.tga textures/coop_gbs/gbs_zoo/Falk4.tga
        blendFunc GL_DST_COLOR GL_ZERO
    }
}

textures/coop_gbs/gbs_zoo/ulrike0
{
    qer_editorimage textures/coop_gbs/GBS_Zoo/ulrike0.tga
    {
        map $lightmap
    }
    {
        animMap 0.5 textures/coop_gbs/gbs_zoo/ulrike0.tga textures/coop_gbs/gbs_zoo/ulrike1.tga textures/coop_gbs/gbs_zoo/ulrike2.tga textures/coop_gbs/gbs_zoo/ulrike3.tga textures/coop_gbs/gbs_zoo/ulrike4.tga 
        blendFunc GL_DST_COLOR GL_ZERO
    }
}

textures/coop_gbs/gbs_zoo/7voywip
{
    qer_editorimage textures/coop_gbs/GBS_Zoo/7voywip.tga
    {
        map $lightmap
    }
    {
        animMap 0.5 textures/coop_gbs/gbs_zoo/7voywip.tga textures/coop_gbs/gbs_zoo/7rainyday.tga textures/coop_gbs/gbs_zoo/7pano.tga textures/coop_gbs/gbs_zoo/7landing.tga textures/coop_gbs/gbs_zoo/7ether.tga 
        blendFunc GL_DST_COLOR GL_ZERO
    }
}

textures/coop_gbs/gbs_zoo/pady
{
    qer_editorimage textures/coop_gbs/GBS_Zoo/pady3.tga
    {
        map $lightmap
    }
    {
        animMap 0.5 textures/coop_gbs/gbs_zoo/pady0.tga textures/coop_gbs/gbs_zoo/pady1.tga textures/coop_gbs/gbs_zoo/pady2.tga textures/coop_gbs/gbs_zoo/pady3.tga textures/coop_gbs/gbs_zoo/bicko.tga 
        blendFunc GL_DST_COLOR GL_ZERO
    }
}

textures/coop_gbs/gbs_zoo/argyle
{
    qer_editorimage textures/coop_gbs/GBS_Zoo/argyle0.tga
    {
        map $lightmap
    }
    {
        animMap 0.5 textures/coop_gbs/gbs_zoo/argyle0.tga textures/coop_gbs/gbs_zoo/argyle1.tga textures/coop_gbs/gbs_zoo/argyle2.tga textures/coop_gbs/gbs_zoo/argyle3.tga textures/coop_gbs/gbs_zoo/argyle4.tga
        blendFunc GL_DST_COLOR GL_ZERO
    }
}

textures/coop_gbs/gbs_zoo/Final_Frontier0
{
    qer_editorimage textures/coop_gbs/GBS_Zoo/Final_Frontier0.tga
    {
        map $lightmap
    }
    {
        animMap 0.5 textures/coop_gbs/gbs_zoo/Final_Frontier0.tga textures/coop_gbs/gbs_zoo/Final_Frontier1.tga textures/coop_gbs/gbs_zoo/Final_Frontier2.tga textures/coop_gbs/gbs_zoo/Final_Frontier3.tga textures/coop_gbs/gbs_zoo/Final_Frontier4.tga
        blendFunc GL_DST_COLOR GL_ZERO
    }
}

