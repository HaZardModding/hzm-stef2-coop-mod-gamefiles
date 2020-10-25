textures/coop_paradiseIsland/metal_pipe
{
cull none
qer_editorimage textures/borg/met_pipe1.tga
{
                map $lightmap
		rgbGen identity
//		blendFunc GL_DST_COLOR GL_ZERO
//		depthFunc equal
	}
	{
		map textures/coop_paradiseIsland/id_pipefx.tga
		blendfunc blend
		tcmod scroll 0 2
		detail
	}
   	{
		map textures/borg/met_pipe1.tga
		blendFunc filter
		rgbGen identity
		detail
	}
}
textures/coop_paradiseIsland/id_light2
{
	qer_editorimage textures/coop_paradiseIsland/id_light2.tga
	surfaceparm nomarks
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/coop_paradiseIsland/id_light2.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}

	
	{
		map textures/shaderfx/elight3glow.tga
		blendfunc GL_ONE GL_ONE
		rgbGen wave sin 0.81 0.1 0 1
	}
}
textures/coop_paradiseIsland/id_light1
{
	qer_editorimage textures/coop_paradiseIsland/id_light1.tga
	surfaceparm nomarks
	{
		map $lightmap
		rgbGen identity
	}
	{
		map textures/coop_paradiseIsland/id_light1.tga
		blendFunc GL_DST_COLOR GL_ZERO
		rgbGen identity
	}

	
	{
		map textures/shaderfx/elight2glow.tga
		blendfunc GL_ONE GL_ONE
		rgbGen wave sin 0.81 0.1 0 1
	}
}
textures/coop_paradiseIsland/id_ceiling
{
	qer_editorimage textures/coop_paradiseIsland/id_ceiling.tga
	

        {
		map textures/env/env_drull_ruins2_interior1.tga
  		tcGen environment
		rgbGen identity
	}
        {
	        map textures/coop_paradiseIsland/id_ceiling.tga
		blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA
	        rgbGen identity
	}
        {
		map $lightmap
                blendfunc gl_dst_color gl_zero
		rgbGen identity
	}
}