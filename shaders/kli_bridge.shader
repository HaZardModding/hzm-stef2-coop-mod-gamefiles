//////////////////////////////////////
//Klingon Lcars
//Made/Edited by -explorer-
//explorer@exp-ind.com
//
//////////////////////////////////////
//
textures/kli_bridge/kb_lcars01
{
	qer_editorimage textures/kli_bridge/kb_lcars01.tga
	surfaceparm nomarks
	{
		map $lightmap 
		rgbGen identity
		tcGen lightmap 
	}
	{
		map textures/kli_bridge/kb_lcars01.tga
		blendfunc filter
		rgbGen identity
	}
	{
		map textures/kli_bridge/kb_lcars01a.tga
		blendfunc add
		rgbGen wave sin 0.95 0.1 0 1 
	}
}

textures/kli_bridge/kb_lcars02
{
	qer_editorimage textures/kli_bridge/kb_lcars02.tga
	surfaceparm nomarks
	{
		map $lightmap 
		rgbGen identity
		tcGen lightmap 
	}
	{
		map textures/kli_bridge/kb_lcars02.tga
		blendfunc filter
		rgbGen identity
	}
	{
		map textures/kli_bridge/kb_lcars02a.tga
		blendfunc add
		rgbGen wave sin 0.95 0.1 0 1 
	}
}

textures/kli_bridge/kb_lcars03
{
	qer_editorimage textures/kli_bridge/kb_lcars03.tga
	surfaceparm nomarks
	{
		map $lightmap 
		rgbGen identity
		tcGen lightmap 
	}
	{
		map textures/kli_bridge/kb_lcars03.tga
		blendfunc filter
		rgbGen identity
	}
	{
		map textures/kli_bridge/kb_lcars03a.tga
		blendfunc add
		rgbGen wave sin 0.95 0.1 0 1 
	}
}

textures/kli_bridge/kb_lcars04
{
	qer_editorimage textures/kli_bridge/kb_lcars04.tga
	surfaceparm nomarks
	{
		map $lightmap 
		rgbGen identity
		tcGen lightmap 
	}
	{
		map textures/kli_bridge/kb_lcars04.tga
		blendfunc filter
		rgbGen identity
	}
	{
		map textures/kli_bridge/kb_lcars04a.tga
		blendfunc add
		rgbGen wave sin 0.95 0.1 0 1 
	}
}

//////////////////////////////////////
//Klingon lights
//Made/Edited by -explorer-
//explorer@exp-ind.com
//
//////////////////////////////////////
//
textures/kli_bridge/kb_light01
{
	qer_editorimage textures/kli_bridge/kb_light01.tga
	surfaceparm nomarks
	{
		map $lightmap 
		rgbGen identity
		tcGen lightmap 
	}
	{
		map textures/kli_bridge/kb_light01.tga
		blendfunc filter
		rgbGen identity
	}
	{
		map textures/kli_bridge/kb_light01a.tga
		blendfunc add
		rgbGen wave sin 0.95 0.1 0 1 
	}
}

textures/kli_bridge/kb_light02
{
	qer_editorimage textures/kli_bridge/kb_light02.tga
	surfaceparm nomarks
	{
		map $lightmap 
		rgbGen identity
		tcGen lightmap 
	}
	{
		map textures/kli_bridge/kb_light02.tga
		blendfunc filter
		rgbGen identity
	}
	{
		map textures/kli_bridge/kb_light02a.tga
		blendfunc add
		rgbGen wave sin 0.95 0.1 0 1 
	}
}

textures/kli_bridge/kb_light03
{
	qer_editorimage textures/kli_bridge/kb_light03.tga
	surfaceparm nomarks
	{
		map $lightmap 
		rgbGen identity
		tcGen lightmap 
	}
	{
		map textures/kli_bridge/kb_light03.tga
		blendfunc filter
		rgbGen identity
	}
	{
		map textures/kli_bridge/kb_light03a.tga
		blendfunc add
		rgbGen wave sin 0.95 0.1 0 1 
	}
}

//////////////////////////////////////
//Klingon Pipes 
//Made/Edited by -explorer-
//explorer@exp-ind.com
//
//////////////////////////////////////
//
textures/kli_bridge/kb_pipe01
{
	qer_editorimage textures/kli_bridge/kb_pipe01.tga
	{
		map textures/tex_fx/tf_glare02.tga
		rgbGen identity
		tcGen environment 
	}
	{
		map textures/kli_bridge/kb_pipe01.tga
		blendfunc gl_src_color gl_src_color
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc filter
		tcGen lightmap 
	}
}
