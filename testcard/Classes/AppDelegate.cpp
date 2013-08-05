#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "SceneManager.h"

USING_NS_CC;

Size designsize= {480, 320};

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    Director* director = Director::getInstance();
    EGLView* eglView = EGLView::getInstance();
    
    Size frameSize = eglView->getFrameSize();

    director->setOpenGLView(eglView);
    eglView->setDesignResolutionSize(designsize.width, designsize.height, ResolutionPolicy::NO_BORDER);
	director->setContentScaleFactor(MIN(frameSize.width/designsize.width, frameSize.height/designsize.height));
    
    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    //Scene *scene = HelloWorld::scene();
    CSceneManager::sharedSceneManager()->runWithSceneId(EN_SCENE_MAIN);

    // run
    //director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
