// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=hiLAx_YsPy0&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=8
#include "AnimatedTexture.h"

// Carga la animacion de su archivo en la computadora/constructor
AnimatedTexture::AnimatedTexture(std::string filename, int x, int y, int w, int h, int frameCount, float animationSpeed, ANIM_DIR animationDir)
	: Texture(filename, x, y, w, h) 
{
	mTimer = Timer::Instance();

	mStartX = x;
	mStartY = y;

	mFrameCount = frameCount;
	mAnimationSpeed = animationSpeed;
	mTimePerFrame = mAnimationSpeed / mFrameCount;
	mAnimationTimer = 0.0f;

	mAnimationDirection = animationDir;

	mAnimationDone = false;

	mWrapMode = loop;
}

// Destructor
AnimatedTexture::~AnimatedTexture() {

}

// guarda el tipo de corte de la animacion 1 = loop, 0 = once
void AnimatedTexture::WrapMode(WRAP_MODE mode) {
	mWrapMode = mode;
}

// para actualizar las frames de la animacion
void AnimatedTexture::Update() {
	if (!mAnimationDone) {
		mAnimationTimer += mTimer->DeltaTime();

		// Solamente se repite si el WrapMode es loop
		if (mAnimationTimer >= mAnimationSpeed) {
			if (mWrapMode == loop) {
				mAnimationTimer -= mAnimationSpeed;
			}
			else {
				mAnimationDone = true;
				mAnimationTimer = mAnimationSpeed - mTimePerFrame;
			}
		}
		if (mAnimationDirection == horizontal) {
			mClipRect.x = mStartX + (int)(mAnimationTimer / mTimePerFrame) * mWidth;
		}
		else {
			mClipRect.y = mStartY + (int)(mAnimationTimer / mTimePerFrame) * mHeight;
		}
	}
}
// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=hiLAx_YsPy0&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=8