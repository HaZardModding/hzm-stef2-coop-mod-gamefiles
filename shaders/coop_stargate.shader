textures/coop_mod/gate/gatefront
{
	qer_editorimage textures/coop_mod/gate/gatefront.tga
	{
		map textures/env/env_metal2.tga
		rgbGen identity
		tcMod scale 0.3 0.3
		tcGen environment
		//detail
	}	
	{
		map textures/coop_mod/gate/gatefront.tga
		blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA	
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc gl_dst_color gl_zero
		rgbGen identity
	}
}

textures/coop_mod/gate/gateback
{
	qer_editorimage textures/coop_mod/gate/gateback.tga
	{
		map textures/env/env_metal2.tga
		rgbGen identity
		tcMod scale 0.3 0.3
		tcGen environment 
		//detail
	}	
	{
		map textures/coop_mod/gate/gateback.tga
		blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc gl_dst_color gl_zero
		rgbGen identity
	}
}

textures/coop_mod/gate/nedge
{
	qer_editorimage textures/coop_mod/gate/nedge.tga
	{
		map textures/env/env_metal2.tga
		rgbGen identity
		tcMod scale 0.3 0.3
		tcGen environment 
		//detail
	}	
	{
		map textures/coop_mod/gate/nedge.tga
		blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc gl_dst_color gl_zero
		rgbGen identity
	}
}

textures/coop_mod/gate/nchevsdarker
{
	qer_editorimage textures/coop_mod/gate/nchevsdarker.tga
		{
		map textures/env/env_metal2.tga
		rgbGen identity
		tcMod scale 0.3 0.3
		tcGen environment 
		//detail
	}
	{
		map textures/coop_mod/gate/nchevsdarker.tga
		blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc gl_dst_color gl_zero
		rgbGen identity
	}
}

textures/coop_mod/gate/splits
{
	qer_editorimage textures/coop_mod/gate/splits.tga
	{
		map textures/env/env_metal2.tga
		rgbGen identity
		tcMod scale 0.3 0.3
		tcGen environment 
		//detail
	}
	{
		map textures/coop_mod/gate/splits.tga
		blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc gl_dst_color gl_zero
		rgbGen identity
	}
}

textures/coop_mod/gate/noff
{
	qer_editorimage textures/coop_mod/gate/noff.tga
	{
		map textures/coop_mod/gate/noff.tga
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc gl_dst_color gl_zero
		rgbGen identity
	}
}

textures/coop_mod/gate/anon
{
	qer_editorimage textures/coop_mod/gate/anon.tga
	surfaceparm nolightmap
	{
		map textures/coop_mod/gate/noff.tga
		rgbGen identity
	}
	{
		map textures/coop_mod/gate/anon.tga
		blendfunc add
		rgbGen identity
	}
	{
		map textures/coop_mod/gate/anon.tga
		blendfunc add
		rgbGen identity
	}
}

textures/coop_mod/rings/rings
{
	qer_editorimage textures/coop_mod/rings/rings.tga
	{
		map textures/env/env_metal2.tga
		rgbGen identity
		tcMod scale 0.3 0.3
		tcGen environment 
		//detail
	}
	{
		map textures/coop_mod/rings/rings.tga
		blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc gl_dst_color gl_zero
		rgbGen identity 
	}
}

textures/coop_mod/dhd/center_light
{
	qer_editorimage textures/coop_mod/dhd/center_light.tga
	{
		map textures/env/env_metal2.tga
		rgbGen identity
		tcMod scale 0.3 0.3
		tcGen environment
		//detail
	}	
	{
		map textures/coop_mod/dhd/center_light.tga
		blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc gl_dst_color gl_zero
		rgbGen identity
	}
}

textures/coop_mod/dhd/center_light_on
{
	qer_editorimage textures/coop_mod/dhd/center_light_on.tga
	{
		map textures/env/env_metal2.tga
		rgbGen identity
		tcMod scale 0.3 0.3
		tcGen environment 
		//detail
	}	
	surfaceparm nolightmap
	{
		map textures/coop_mod/dhd/center_light.tga
		blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA
		rgbGen identity
	}
	{
		map textures/coop_mod/dhd/center_light_on.tga
		blendfunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA
	}
}

textures/coop_mod/dhd/dhd_pattern
{
	qer_editorimage textures/coop_mod/dhd/dhd_pattern.tga
	{
		map textures/env/env_metal2.tga
		rgbGen identity
		tcMod scale 0.2 0.2
		tcGen environment 
		//detail
	}	
	{
		map textures/coop_mod/dhd/dhd_pattern.tga
		blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc gl_dst_color gl_zero
		rgbGen identity
	}
}

textures/coop_mod/dhd/dhdbase
{
	qer_editorimage textures/coop_mod/dhd/dhdbase.tga
	{
		map textures/env/env_metal2.tga
		rgbGen identity
		tcMod scale 0.2 0.2
		tcGen environment 
		//detail
	}	
	{
		map textures/coop_mod/dhd/dhdbase.tga
		blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc gl_dst_color gl_zero
		rgbGen identity
	}
}

textures/coop_mod/dhd/glyph
{
	qer_editorimage textures/coop_mod/dhd/glyph.tga
	{
		map textures/env/env_metal2.tga
		rgbGen identity
		tcMod scale 0.2 0.2
		tcGen environment 
		//detail
	}	
	{
		map textures/coop_mod/dhd/glyph.tga
		blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc gl_dst_color gl_zero
		rgbGen identity
	}
}

textures/coop_mod/dhd/glyph_base
{
	qer_editorimage textures/coop_mod/dhd/glyph_base.tga
	{
		map textures/env/env_metal2.tga
		rgbGen identity
		tcMod scale 0.2 0.2
		tcGen environment 
		//detail
	}	
	{
		map textures/coop_mod/dhd/glyph_base.tga
		blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc gl_dst_color gl_zero
		rgbGen identity
	}
}

textures/coop_mod/dhd/glyph_base_on
{
	qer_editorimage textures/coop_mod/dhd/glyph_base_on.tga
	{
		map textures/env/env_metal2.tga
		rgbGen identity
		tcMod scale 0.2 0.2
		tcGen environment 
		//detail
	}
	{
		map textures/coop_mod/dhd/glyph_base_on.tga
		blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc gl_dst_color gl_zero
		rgbGen identity
	}
}

textures/coop_mod/dhd/glyph_on
{
	qer_editorimage textures/coop_mod/dhd/glyph_on.tga
	{
		map textures/env/env_metal2.tga
		rgbGen identity
		tcMod scale 0.2 0.2
		tcGen environment 
		//detail
	}
	{
		map textures/coop_mod/dhd/glyph.tga
		blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA
		rgbGen identity
	}
	{
		map textures/coop_mod/dhd/glyph_on.tga
		blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc gl_dst_color gl_zero
		rgbGen identity
	}
}

textures/coop_mod/gate/iris
{
	qer_editorimage textures/coop_mod/gate/iris.tga
	{
		map textures/env/env_metal2.tga
		rgbGen identity
		tcMod scale 0.3 0.3
		tcGen environment 
		//detail
	}	
	{
		map textures/coop_mod/gate/iris.tga
		blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc gl_dst_color gl_zero
		rgbGen identity
	}
}

