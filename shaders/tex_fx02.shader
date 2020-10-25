textures/tex_fx/tf_fog01
{
	surfaceparm nolightmap
	surfaceparm nonsolid
	surfaceparm trans
	{
		map textures/tex_fx/tf_fog01.tga
		blendfunc add
		tcMod rotate -3
	}
	{
		map textures/tex_fx/tf_fog01a.tga
		blendfunc filter
		tcMod rotate 4
	}
}

