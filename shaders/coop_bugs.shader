//Special Texture Properties for the level coop_bugs

textures/coop_bugs/waterfall
{
	surfaceparm nonsolid
	surfaceparm nolightmap
	surfaceparm trans
	surfaceparm water
	tessSize 128
	
	qer_editorimage textures/drull_ruins2_exterior/swampwater1b.tga
	{
		map textures/drull_ruins2_exterior/swampwater1b.tga
		blendfunc blend
		rgbGen identity
		alphagen constant .2
		tcmod scroll .5 0 
		tcMod turb 0.015 0.019 0 0.19
	}  
	{
		map textures/env/env_diffused.tga
		blendFunc blend
		alphagen constant .2
		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA		
		tcGen environment
		rgbgen identity
	}
	{
		map textures/drull_ruins2_exterior/swampwater1b.tga
		blendFunc blend
		tcMod turb 0.015 0.015 0 0.15
		tcmod scroll .05 0.0251
		alphagen constant .3
		rgbGen identity
	}
}

textures/coop_bugs/water-noDeform
{
	surfaceparm nonsolid
	surfaceparm nolightmap
	surfaceparm trans
	surfaceparm water
	tessSize 128

	qer_editorimage textures/drull_ruins2_exterior/swampwater1b.tga
	{
		map textures/drull_ruins2_exterior/swampwater1b.tga
		blendfunc blend
		rgbGen identity
		alphagen constant .2
		tcmod scroll .02 0 
		tcMod turb 0.015 0.019 0 0.19
	}  
	{
		map textures/env/env_diffused.tga
		blendFunc blend
		alphagen constant .2
		blendFunc GL_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA		
		tcGen environment
		rgbgen identity
	}
	{
		map textures/drull_ruins2_exterior/swampwater1b.tga
		blendFunc blend
		tcMod turb 0.015 0.015 0 0.15
		tcmod scroll .02 0.0251
		alphagen constant .3
		rgbGen identity
	}
}

coop_bugs-data-anim-excelsior-battle
{
   nomipmaps
   nopicmip
   cull none
   {
		animmap 2 textures/coop_bugs/a1a.tga textures/coop_bugs/a1b.tga textures/coop_bugs/a1c.tga textures/coop_bugs/a1d.tga textures/coop_bugs/a1e.tga textures/coop_bugs/a1f.tga textures/coop_bugs/a1g.tga
		blendfunc blend
   }
}
