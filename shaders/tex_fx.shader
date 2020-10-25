//////////////////////////////////////
//Defiant Hall Wall 04
//Made/Edited by Explorer
//explorer@exp-ind.com
//
//////////////////////////////////////
//
textures/tex_fx/tf_sky01
{
	qer_editorimage textures/tex_fx/tf_sky01.tga
	surfaceparm nolightmap
	{
		map textures/tex_fx/tf_sky01a.tga
		rgbGen identity
		tcGen environment 
	}
	{
		map textures/tex_fx/tf_sky01.tga
		rgbGen identity
		tcGen environment 
	}
	{
		map $lightmap 
		blendfunc filter
		tcGen lightmap 
	}
}

