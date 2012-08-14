#ifndef _GUIIMAGE_H_
#define _GUIIMAGE_H_

#include "../GuiComponent.h"
#include <SDL/SDL.h>
#include <SDL/SDL_thread.h>
#include <string>

class GuiImage : public GuiComponent
{
public:
	GuiImage(int offsetX = 0, int offsetY = 0, std::string path = "", unsigned int maxWidth = 0, unsigned int maxHeight = 0, bool resizeExact = false);
	~GuiImage();

	void setImage(std::string path);
	void setOrigin(float originX, float originY);
	void setTiling(bool tile);
	void setAlpha(bool useAlpha);

	int getWidth();
	int getHeight();

	void onRender();

private:
	int mMaxWidth, mMaxHeight;
	float mOriginX, mOriginY;
	bool mResizeExact, mTiled, mUseAlpha;

	void loadImage(std::string path);
	void resizeSurface(SDL_Surface** surfRef);
	void updateRect();

	std::string mPath;

	SDL_Surface* mSurface;
	int mOffsetX, mOffsetY;
	SDL_Rect mRect;
};

#endif