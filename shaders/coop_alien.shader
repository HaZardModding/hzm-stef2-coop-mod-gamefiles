textures/coop_alien/dust_moving_flat_floor_trans
{
//	sort additive
	surfaceparm nolightmap
	surfaceparm nonsolid
	surfaceparm trans
	surfaceparm nomarks
	cull none
	//nopicmip
	qer_editorimage textures/coop_alien/dust_moving_flat_floor_trans.tga
	qer_trans 0.5
	{
  	map textures/coop_alien/dust_moving_flat_floor_trans.tga
	blendFunc blend
	alphaGen dot
	alphaFunc GT0
	rgbGen constant 0.6 0.55 0.5
 	//depthWrite
	//depthFunc equal
	tcmod scroll 0.3 0
	Detail
	}
}
textures/coop_alien/dust_moving_flat_floor_trans2
{
	surfaceparm nolightmap
	surfaceparm nonsolid
	surfaceparm trans
	surfaceparm nomarks
	cull none
	qer_editorimage textures/coop_alien/dust_moving_flat_floor_trans2.tga
	qer_trans 0.5
	{
  	map textures/coop_alien/dust_moving_flat_floor_trans2.tga
	blendFunc blend
	alphaGen dot
	alphaFunc GT0
	rgbGen constant 0.6 0.55 0.5
	tcmod scroll 0.3 0
	Detail
	}
}
textures/coop_alien/dust_moving_flat_floor_trans3
{
	surfaceparm nolightmap
	surfaceparm nonsolid
	surfaceparm trans
	surfaceparm nomarks
	cull none
	qer_editorimage textures/coop_alien/dust_moving_flat_floor_trans3.tga
	qer_trans 0.5
	{
  	map textures/coop_alien/dust_moving_flat_floor_trans3.tga
	blendFunc blend
	alphaGen dot
	alphaFunc GT0
	rgbGen constant 0.6 0.55 0.5
	//depthFunc equal
	tcmod scroll 0.1 0
	Detail
	}
}
textures/coop_alien/rain
{
	surfaceparm nolightmap
	surfaceparm nonsolid
	surfaceparm trans
	surfaceparm nomarks
	cull none
	//deformVertexes wave 1096 sin 0 8 0 0.25
	//deformVertexes wave 1096 sin 8 8 22 11
	deformVertexes wave 1096 sin 8 8 22 33
	
	qer_editorimage textures/coop_alien/rain.tga
	qer_trans 0.2
        {
		//blendFunc blend
        map textures/coop_alien/rain.tga
		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
		blendfunc blend
        //alphaFunc GT128
		tcmod scroll 0.1 -3
		//tcMod scale 6 1.5
		//rgbGen constant 0.4 0.4 0.5
		rgbGen constant 0.3 0.3 0.35
		//depthWrite
		//blendFunc GL_DST_COLOR GL_ZERO
        }
        {
		map $lightmap
		depthFunc equal
		rgbGen identity
		blendFunc GL_DST_COLOR GL_ZERO
		}
}
textures/coop_alien/fan_edgeShadow
{
//	sort additive
	surfaceparm nolightmap
	surfaceparm nonsolid
	surfaceparm trans
	surfaceparm nomarks
	cull none
	nopicmip
	qer_editorimage textures/coop_alien/fan_edgeS.tga
//	qer_trans 0.5
	{
		map textures/coop_alien/fan_edgeS.tga
		blendFunc blend
		alphaGen dot
		alphaFunc GT0
		rgbGen constant 0.200000 0.150000 0.100000
	}
}

textures/coop_alien/fan_shadowGround
{
	sort Opaque
	surfaceparm nolightmap
	surfaceparm nonsolid
	surfaceparm trans
	surfaceparm nomarks
	cull none
	nopicmip
	qer_editorimage textures/coop_alien/fan_groundS.tga
//	qer_trans 0.5
	{
		map textures/coop_alien/fan_groundS.tga
		blendFunc blend
		//alphaGen dot
		alphaFunc GT0
		//rgbGen constant 0.200000 0.150000 0.100000
		rgbGen constant 0 0 0
	}
}

textures/coop_alien/iced
{
	qer_editorimage textures/coop_alien/iced.tga
	qer_trans 0.5
//	surfaceparm nolightmap
	{
		map textures/test/clearglass.tga
		blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA
		alphaGen constant 0.99
//		rgbGen lightingDiffuse
	}
	{
		map $lightmap
		blendfunc GL_DST_COLOR GL_ZERO
//		depthFunc equal
	}
}

textures/coop_alien/fog_white-512
{
	qer_editorimage textures/common/fog.tga
	surfaceparm	trans
	surfaceparm	nonsolid
	surfaceparm	fog
	surfaceparm nodrop
	surfaceparm nolightmap
	surfaceparm nomarks
	q3map_globaltexture
	//fogonly
	fogparms 1 1 1 512
	//fogparms 1 1 1 1024

	{
		map textures/fx/fog.tga
		blendfunc gl_dst_color gl_zero
		tcmod scale -.05 -.05
		tcmod scroll .01 -.01
		rgbgen identity
	}
	{
		map textures/fx/fog.tga
		blendfunc gl_dst_color gl_zero
		tcmod scale .05 .05
		tcmod scroll .01 -.01
		rgbgen identity
	}
}

textures/coop_alien/fog_white-256
{
	qer_editorimage textures/common/fog.tga
	surfaceparm	trans
	surfaceparm	nonsolid
	surfaceparm	fog
	surfaceparm nodrop
	surfaceparm nolightmap
	surfaceparm nomarks
	q3map_globaltexture
	//fogonly
	fogparms 1 1 1 256
	//fogparms 1 1 1 1024

	{
		map textures/fx/fog.tga
		blendfunc gl_dst_color gl_zero
		tcmod scale -.05 -.05
		tcmod scroll .01 -.01
		rgbgen identity
	}
	{
		map textures/fx/fog.tga
		blendfunc gl_dst_color gl_zero
		tcmod scale .05 .05
		tcmod scroll .01 -.01
		rgbgen identity
	}
}

textures/coop_alien/fog_white-128
{
	qer_editorimage textures/common/fog.tga
	surfaceparm	trans
	surfaceparm	nonsolid
	surfaceparm	fog
	surfaceparm nodrop
	surfaceparm nolightmap
	surfaceparm nomarks
	q3map_globaltexture
	fogonly
	fogparms 1 1 1 512
}

