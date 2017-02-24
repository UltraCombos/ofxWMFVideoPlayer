#pragma once


//ofxWMFVideoPlayer addon written by Philippe Laulheret for Second Story (secondstory.com)
//Based upon Windows SDK samples
//MIT Licensing


#include "ofMain.h"
#include "ofxWMFVideoPlayerUtils.h"

#include "EVRPresenter.h"



class ofxWMFVideoPlayer;


class CPlayer;
class ofxWMFVideoPlayer : public ofBaseVideoPlayer {

private:
	static int _instanceCount;


	HWND _hwndPlayer;

	BOOL bRepaintClient;


	int _width;
	int _height;


	bool _waitForLoadedToPlay;
	bool _isLooping;
	bool _wantToSetVolume;
	float _currentVolume;

	bool _sharedTextureCreated;

	ofTexture _tex;

	BOOL InitInstance();


	void OnPlayerEvent(HWND hwnd, WPARAM pUnkPtr);

	float _frameRate;



public:
	CPlayer* _player;

	int _id;


	ofxWMFVideoPlayer();
	~ofxWMFVideoPlayer();

	bool				load(string name) override;

	void				close() override;
	void				update() override;

	void				play() override;
	void				stop() override;
	void				pause();

	ofTexture *        getTexturePtr() override;

	float				getPosition() const override;
	float				getDuration() const override;
	float				getFrameRate();

	void				setPosition(float pos) override;

	void				setVolume(float vol) override;
	float				getVolume();

	float				getHeight();
	float				getWidth();

	bool				isPlaying() const override;
	bool				isStopped();
	bool				isPaused() const override;

	void				setLoopState(ofLoopType state) override;


	void draw(int x, int y, int w, int h);
	void draw(int x, int y) { draw(x, y, getWidth(), getHeight()); }


	HWND getHandle() { return _hwndPlayer; }
	LRESULT WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	static void forceExit();


	// not implement yet
	ofPixels pix;

	ofPixels & getPixels() override;
	const ofPixels & getPixels() const override;
	bool isFrameNew() const override;
	bool setPixelFormat(ofPixelFormat pixelFormat) override;
	ofPixelFormat getPixelFormat() const override;
	float getWidth() const override;
	float getHeight() const override;
	bool isLoaded() const override;
	bool getIsMovieDone() const override;
	int getTotalNumFrames() const override;
};