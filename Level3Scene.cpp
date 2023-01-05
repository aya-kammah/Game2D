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

#include "HelloWorldScene.h"
#include "Level2Scene.h"
#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "GameOverScene1.h"
#include "Definitions.h"
#include "Level3Scene.h"
#include "GameOverScene3.h"
#include "YouWinScene.h"

USING_NS_CC;

Scene* Level3Scene::createScene()
{
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setGravity(Vec2(0, -600));
    //scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    auto layer = Level3Scene::create();
    layer->SetPhysisicsWorld(scene->getPhysicsWorld());
    scene->addChild(layer);
    return scene;
}



// on "init" you need to initialize your instance
bool Level3Scene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //Background de notre jeux 
    auto backgroundSprite = Sprite::create("LEVE1BG.png");
    backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(backgroundSprite); 

    //contoure physique de notre jeux 
    auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
    auto edgeNode = Node::create();
    edgeNode->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    edgeNode->setPhysicsBody(edgeBody);
    this->addChild(edgeNode);

    //notre joueure 
    mySprite = Sprite::create("PPPP.png");
    mySprite->setPosition(Point(visibleSize.width / 8 + origin.x, visibleSize.height / 2 + origin.y));
    addChild(mySprite);

    // Creez un corps physique pour le joueur et attachele au sprite
    auto body = PhysicsBody::createBox(mySprite->getContentSize());
    body->setCollisionBitmask(mySprite_COLLISION_BITMASK);
    body->setContactTestBitmask(true);
    mySprite->setPhysicsBody(body);

    //
    backgroundSprite = Sprite::create("Rock4.png");
    backgroundSprite->setPosition(Vec2(60, 70));
    addChild(backgroundSprite);
    // Cr�ez un corps physique pour rock1
    auto Rock4 = PhysicsBody::createBox(backgroundSprite->getContentSize());
    Rock4->setDynamic(false);
    backgroundSprite->setPhysicsBody(Rock4);

    auto RetryItem = MenuItemImage::create("sign home.png", "home dark.png", CC_CALLBACK_1(Level3Scene::GoToHelloWorldScene, this));
    RetryItem->setPosition(Vec2(23, 275));
    auto menu = Menu::create(RetryItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);


    backgroundSprite = Sprite::create("planet1.png");
    backgroundSprite->setPosition(Vec2(200, 100));
    addChild(backgroundSprite);
    auto planet1 = PhysicsBody::createBox(backgroundSprite->getContentSize());
    planet1->setDynamic(false);
    backgroundSprite->setPhysicsBody(planet1);

    backgroundSprite = Sprite::create("planet2.png");
    backgroundSprite->setPosition(Vec2(300, 120));
    addChild(backgroundSprite);
    auto planet2 = PhysicsBody::createBox(backgroundSprite->getContentSize());
    planet2->setDynamic(false);
    backgroundSprite->setPhysicsBody(planet2);

    backgroundSprite = Sprite::create("planet3.png");
    backgroundSprite->setPosition(Vec2(400, 140));
    addChild(backgroundSprite);
    auto planet3 = PhysicsBody::createBox(backgroundSprite->getContentSize());
    planet3->setDynamic(false);
    backgroundSprite->setPhysicsBody(planet3);


    backgroundSprite = Sprite::create("door.png");
    backgroundSprite->setPosition(Vec2(470, 200));
    addChild(backgroundSprite);
    auto door3 = PhysicsBody::createBox(backgroundSprite->getContentSize());
    door3->setCollisionBitmask(DOOR_COLLISION_BITMASK);
    door3->setContactTestBitmask(true);
    door3->setDynamic(false);
    backgroundSprite->setPhysicsBody(door3);

    backgroundSprite = Sprite::create("FIRE2.png");
    backgroundSprite->setPosition(Vec2(200, 45));
    addChild(backgroundSprite);
    auto fire2 = PhysicsBody::createBox(backgroundSprite->getContentSize());
    fire2->setCollisionBitmask(FIRE_COLLISION_BITMASK);
    fire2->setContactTestBitmask(true);
    fire2->setDynamic(false);
    backgroundSprite->setPhysicsBody(fire2);

    backgroundSprite = Sprite::create("FIRE2.png");
    backgroundSprite->setPosition(Vec2(138, 45));
    addChild(backgroundSprite);
    auto fire3 = PhysicsBody::createBox(backgroundSprite->getContentSize());
    fire3->setCollisionBitmask(FIRE_COLLISION_BITMASK);
    fire3->setContactTestBitmask(true);
    fire3->setDynamic(false);
    backgroundSprite->setPhysicsBody(fire3);


    backgroundSprite = Sprite::create("FIRE2.png");
    backgroundSprite->setPosition(Vec2(262, 45));
    addChild(backgroundSprite);
    auto fire4 = PhysicsBody::createBox(backgroundSprite->getContentSize());
    fire4->setCollisionBitmask(FIRE_COLLISION_BITMASK);
    fire4->setContactTestBitmask(true);
    fire4->setDynamic(false);
    backgroundSprite->setPhysicsBody(fire4);



    backgroundSprite = Sprite::create("FIRE2.png");
    backgroundSprite->setPosition(Vec2(324, 45));
    addChild(backgroundSprite);
    auto fire5 = PhysicsBody::createBox(backgroundSprite->getContentSize());
    fire5->setCollisionBitmask(FIRE_COLLISION_BITMASK);
    fire5->setContactTestBitmask(true);
    fire5->setDynamic(false);
    backgroundSprite->setPhysicsBody(fire5);


    backgroundSprite = Sprite::create("FIRE2.png");
    backgroundSprite->setPosition(Vec2(386, 45));
    addChild(backgroundSprite);
    auto fire6 = PhysicsBody::createBox(backgroundSprite->getContentSize());
    fire6->setCollisionBitmask(FIRE_COLLISION_BITMASK);
    fire6->setContactTestBitmask(true);
    fire6->setDynamic(false);
    backgroundSprite->setPhysicsBody(fire6);


    backgroundSprite = Sprite::create("FIRE2.png");
    backgroundSprite->setPosition(Vec2(448, 45));
    addChild(backgroundSprite);
    auto fire7 = PhysicsBody::createBox(backgroundSprite->getContentSize());
    fire7->setCollisionBitmask(FIRE_COLLISION_BITMASK);
    fire7->setContactTestBitmask(true);
    fire7->setDynamic(false);
    backgroundSprite->setPhysicsBody(fire7);

    auto  keyboardListener = EventListenerKeyboard::create();

    keyboardListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event)
    {
        switch (keyCode)
        {
        case EventKeyboard::KeyCode::KEY_W:
        case EventKeyboard::KeyCode::KEY_UP_ARROW:
            DirY += 3.0f;
            break;
        case EventKeyboard::KeyCode::KEY_A:
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
            DirX -= 3.0f;
            break;
        case EventKeyboard::KeyCode::KEY_S:
        case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
            DirY -= 3.0f;
            break;
        case EventKeyboard::KeyCode::KEY_D:
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
            DirX += 3.0f;
            break;
        }
    };

    keyboardListener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event)
    {
        switch (keyCode)
        {
        case EventKeyboard::KeyCode::KEY_W:
        case EventKeyboard::KeyCode::KEY_UP_ARROW:
            DirY -= 3.0f;
            break;
        case EventKeyboard::KeyCode::KEY_A:
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
            DirX += 3.0f;
            break;
        case EventKeyboard::KeyCode::KEY_S:
        case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
            DirY += 3.0f;
            break;
        case EventKeyboard::KeyCode::KEY_D:
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
            DirX -= 3.0f;
            break;
        }
    };

    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);
    this->scheduleUpdate();


    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(Level3Scene::onContactBegin, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

    return true; 

}
void  Level3Scene::GoToHelloWorldScene(cocos2d::Ref* sender) {

    auto scene = HelloWorldScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void  Level3Scene::update(float dt)
{
    float newPosX = Level3Scene::mySprite->getPositionX() + (DirX);
    float newPosY = Level3Scene::mySprite->getPositionY() + (DirY);

    Level3Scene::mySprite->setPosition(newPosX, newPosY);
}
bool Level3Scene::onContactBegin(cocos2d::PhysicsContact& contact)
{
    PhysicsBody* a = contact.getShapeA()->getBody();
    PhysicsBody* b = contact.getShapeB()->getBody();


    // v�rifiez si le joueur entre en contact avec une pierre
    if ((a->getCollisionBitmask() == mySprite_COLLISION_BITMASK && b->getCollisionBitmask() == FIRE_COLLISION_BITMASK) ||
        (b->getCollisionBitmask() == mySprite_COLLISION_BITMASK && a->getCollisionBitmask() == FIRE_COLLISION_BITMASK))
    {
        // affichez la sc�ne de fin de jeu (game over) ici
        auto scene = GameOverScene3::createScene();
        Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
    }
    // v�rifiez si le joueur entre dans la porte
    if ((a->getCollisionBitmask() == mySprite_COLLISION_BITMASK && b->getCollisionBitmask() == DOOR_COLLISION_BITMASK) ||
        (b->getCollisionBitmask() == mySprite_COLLISION_BITMASK && a->getCollisionBitmask() == DOOR_COLLISION_BITMASK))
    {
        // affichez la sc�ne de victoire ici
        auto scene =YouWinScene::createScene();
        Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
    }
   



    return true;

}




void Level3Scene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
