/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "YouWinScene.h"
#include "Level3Scene.h" 
#include "HelloWorldScene.h"
#include "Definitions.h"
#include "Level1Scene.h"

USING_NS_CC;

Scene* YouWinScene::createScene()
{

    auto scene = Scene::create();
    auto layer = YouWinScene::create();
    scene->addChild(layer);
    return scene;
}


// on "init" you need to initialize your instance
bool YouWinScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto backgroundSprite = Sprite::create("GP3.png");
    backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(backgroundSprite); 

    auto RetryItem = MenuItemImage::create("RETRY.png", "RETRY.png", CC_CALLBACK_1(YouWinScene::GoToLevel1Scene, this));
    RetryItem->setPosition(Vec2(180, 130));
    auto menu = Menu::create(RetryItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);

    auto QuiteItem = MenuItemImage::create("QUIT.png", "dark quit.png", CC_CALLBACK_1(YouWinScene::GoToHelloWorldScene, this));
    QuiteItem->setPosition(Vec2(180, 100));
    menu = Menu::create(QuiteItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
    
   

    
    
    return true;
}

void  YouWinScene::GoToLevel1Scene(cocos2d::Ref* sender) {

    auto scene = Level1Scene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void  YouWinScene::GoToHelloWorldScene(cocos2d::Ref* sender) {

    auto scene = HelloWorldScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}




void YouWinScene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
