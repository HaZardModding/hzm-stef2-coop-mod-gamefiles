textures/stargate/gate/gatefront
{
	qer_editorimage textures/stargate/gate/gatefront.tga
	{
		map textures/env/env_metal2.tga
		rgbGen identity
		tcMod scale 0.3 0.3
		tcGen environment
		//detail
	}	
	{
		map textures/stargate/gate/gatefront.tga
		blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA	
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc gl_dst_color gl_zero
		rgbGen identity
	}
}

textures/stargate/gate/gateback
{
	qer_editorimage textures/stargate/gate/gateback.tga
	{
		map textures/env/env_metal2.tga
		rgbGen identity
		tcMod scale 0.3 0.3
		tcGen environment 
		//detail
	}	
	{
		map textures/stargate/gate/gateback.tga
		blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc gl_dst_color gl_zero
		rgbGen identity
	}
}

textures/stargate/gate/nedge
{
	qer_editorimage textures/stargate/gate/nedge.tga
	{
		map textures/env/env_metal2.tga
		rgbGen identity
		tcMod scale 0.3 0.3
		tcGen environment 
		//detail
	}	
	{
		map textures/stargate/gate/nedge.tga
		blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc gl_dst_color gl_zero
		rgbGen identity
	}
}

textures/stargate/gate/nchevsdarker
{
	qer_editorimage textures/stargate/gate/nchevsdarker.tga
		{
		map textures/env/env_metal2.tga
		rgbGen identity
		tcMod scale 0.3 0.3
		tcGen environment 
		//detail
	}
	{
		map textures/stargate/gate/nchevsdarker.tga
		blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc gl_dst_color gl_zero
		rgbGen identity
	}
}

textures/stargate/gate/splits
{
	qer_editorimage textures/stargate/gate/splits.tga
	{
		map textures/env/env_metal2.tga
		rgbGen identity
		tcMod scale 0.3 0.3
		tcGen environment 
		//detail
	}
	{
		map textures/stargate/gate/splits.tga
		blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc gl_dst_color gl_zero
		rgbGen identity
	}
}

textures/stargate/gate/noff
{
	qer_editorimage textures/stargate/gate/noff.tga
	{
		map textures/stargate/gate/noff.tga
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc gl_dst_color gl_zero
		rgbGen identity
	}
}

textures/stargate/gate/anon
{
	qer_editorimage textures/stargate/gate/anon.tga
	surfaceparm nolightmap
	{
		map textures/stargate/gate/noff.tga
		rgbGen identity
	}
	{
		map textures/stargate/gate/anon.tga
		blendfunc add
		rgbGen identity
	}
	{
		map textures/stargate/gate/anon.tga
		blendfunc add
		rgbGen identity
	}
}

textures/stargate/rings/rings
{
	qer_editorimage textures/stargate/rings/rings.tga
	{
		map textures/env/env_metal2.tga
		rgbGen identity
		tcMod scale 0.3 0.3
		tcGen environment 
		//detail
	}
	{
		map textures/stargate/rings/rings.tga
		blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc gl_dst_color gl_zero
		rgbGen identity 
	}
}

textures/stargate/dhd/center_light
{
	qer_editorimage textures/stargate/dhd/center_light.tga
	{
		map textures/env/env_metal2.tga
		rgbGen identity
		tcMod scale 0.3 0.3
		tcGen environment
		//detail
	}	
	{
		map textures/stargate/dhd/center_light.tga
		blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc gl_dst_color gl_zero
		rgbGen identity
	}
}

textures/stargate/dhd/center_light_on
{
	qer_editorimage textures/stargate/dhd/center_light_on.tga
	{
		map textures/env/env_metal2.tga
		rgbGen identity
		tcMod scale 0.3 0.3
		tcGen environment 
		//detail
	}	
	surfaceparm nolightmap
	{
		map textures/stargate/dhd/center_light.tga
		blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA
		rgbGen identity
	}
	{
		map textures/stargate/dhd/center_light_on.tga
		blendfunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA
	}
}

textures/stargate/dhd/dhd_pattern
{
	qer_editorimage textures/stargate/dhd/dhd_pattern.tga
	{
		map textures/env/env_metal2.tga
		rgbGen identity
		tcMod scale 0.2 0.2
		tcGen environment 
		//detail
	}	
	{
		map textures/stargate/dhd/dhd_pattern.tga
		blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc gl_dst_color gl_zero
		rgbGen identity
	}
}

textures/stargate/dhd/dhdbase
{
	qer_editorimage textures/stargate/dhd/dhdbase.tga
	{
		map textures/env/env_metal2.tga
		rgbGen identity
		tcMod scale 0.2 0.2
		tcGen environment 
		//detail
	}	
	{
		map textures/stargate/dhd/dhdbase.tga
		blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc gl_dst_color gl_zero
		rgbGen identity
	}
}

textures/stargate/dhd/glyph
{
	qer_editorimage textures/stargate/dhd/glyph.tga
	{
		map textures/env/env_metal2.tga
		rgbGen identity
		tcMod scale 0.2 0.2
		tcGen environment 
		//detail
	}	
	{
		map textures/stargate/dhd/glyph.tga
		blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc gl_dst_color gl_zero
		rgbGen identity
	}
}

textures/stargate/dhd/glyph_base
{
	qer_editorimage textures/stargate/dhd/glyph_base.tga
	{
		map textures/env/env_metal2.tga
		rgbGen identity
		tcMod scale 0.2 0.2
		tcGen environment 
		//detail
	}	
	{
		map textures/stargate/dhd/glyph_base.tga
		blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc gl_dst_color gl_zero
		rgbGen identity
	}
}

textures/stargate/dhd/glyph_base_on
{
	qer_editorimage textures/stargate/dhd/glyph_base_on.tga
	{
		map textures/env/env_metal2.tga
		rgbGen identity
		tcMod scale 0.2 0.2
		tcGen environment 
		//detail
	}
	{
		map textures/stargate/dhd/glyph_base_on.tga
		blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc gl_dst_color gl_zero
		rgbGen identity
	}
}

textures/stargate/dhd/glyph_on
{
	qer_editorimage textures/stargate/dhd/glyph_on.tga
	{
		map textures/env/env_metal2.tga
		rgbGen identity
		tcMod scale 0.2 0.2
		tcGen environment 
		//detail
	}
	{
		map textures/stargate/dhd/glyph.tga
		blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA
		rgbGen identity
	}
	{
		map textures/stargate/dhd/glyph_on.tga
		blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc gl_dst_color gl_zero
		rgbGen identity
	}
}

textures/stargate/gate/iris
{
	qer_editorimage textures/stargate/gate/iris.tga
	{
		map textures/env/env_metal2.tga
		rgbGen identity
		tcMod scale 0.3 0.3
		tcGen environment 
		//detail
	}	
	{
		map textures/stargate/gate/iris.tga
		blendFunc GL_ONE_MINUS_SRC_ALPHA GL_SRC_ALPHA
		rgbGen identity
	}
	{
		map $lightmap 
		blendfunc gl_dst_color gl_zero
		rgbGen identity
	}
}

