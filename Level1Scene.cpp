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
#include "Level1Scene.h"
#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "GameOverScene1.h"
#include "Definitions.h"
#include "Level2Scene.h"
#include "YouWinScene.h"
USING_NS_CC;

Scene* Level1Scene::createScene()
{
    auto scene = Scene::createWithPhysics();
    //scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scene->getPhysicsWorld()->setGravity(Vec2(0, -500));
    auto layer = Level1Scene::create();
    layer->SetPhysisicsWorld(scene->getPhysicsWorld());
    scene->addChild(layer);
    return scene;
}



// on "init" you need to initialize your instance
 bool Level1Scene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //bachground de jeux 
    auto backgroundSprite = Sprite::create("LEVE1BG.png");
    backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(backgroundSprite);  

    //le cadre physiqye de jeux 
    //PHYSICSSHAPE_MATERIAL_DEFAULT( density, restitution,friction);
    auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
    auto edgeNode = Node::create();
    edgeNode->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    edgeNode->setPhysicsBody(edgeBody);
    this->addChild(edgeNode);

    // Creez un sprite pour le joueur et ajoutez - lie a la scene
    mySprite = Sprite::create("PPPP.png");
    mySprite->setPosition(Point(visibleSize.width / 8 + origin.x, visibleSize.height / 2 + origin.y));
    addChild(mySprite);

    // Creez un corps physique pour le joueur et attache-le au sprite
    auto body = PhysicsBody::createBox(mySprite->getContentSize());
    body->setCollisionBitmask(mySprite_COLLISION_BITMASK);
    body->setContactTestBitmask(true);
    mySprite->setPhysicsBody(body);


    auto RetryItem = MenuItemImage::create("sign home.png", "home dark.png", CC_CALLBACK_1(Level1Scene::GoToHelloWorldScene, this));
    RetryItem->setPosition(Vec2(23, 275));
    auto menu = Menu::create(RetryItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);

    

    backgroundSprite = Sprite::create("rock.png");
    backgroundSprite->setPosition(Vec2(383, 65));
    addChild(backgroundSprite);

    // Cr�ez un corps physique pour la box1
    auto box1 = PhysicsBody::createBox(backgroundSprite->getContentSize());
    box1->setDynamic(false);
    backgroundSprite->setPhysicsBody(box1);
   

    backgroundSprite = Sprite::create("rock.png");
    backgroundSprite->setPosition(Vec2(102, 65));
    addChild(backgroundSprite);

    // Cr�ez un corps physique pour la box2 
    auto box2 = PhysicsBody::createBox(backgroundSprite->getContentSize());
    box2->setDynamic(false);
    backgroundSprite->setPhysicsBody(box2);

    

    backgroundSprite = Sprite::create("door.png");
    backgroundSprite->setPosition(Vec2(465, 159));
    addChild(backgroundSprite);
    auto door = PhysicsBody::createBox(backgroundSprite->getContentSize());
    door->setCollisionBitmask(DOOR_COLLISION_BITMASK);
    door->setContactTestBitmask(true);
    door->setDynamic(false);
    backgroundSprite->setPhysicsBody(door);



    //Fire obstacle 
    backgroundSprite = Sprite::create("FIRE1.png");
    backgroundSprite->setPosition(Vec2(243, 45));
    addChild(backgroundSprite);

    auto fire = PhysicsBody::createBox(backgroundSprite->getContentSize());
    fire->setCollisionBitmask(FIRE_COLLISION_BITMASK);
    fire->setContactTestBitmask(true);
    fire->setDynamic(false);
    backgroundSprite->setPhysicsBody(fire);


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
    contactListener->onContactBegin = CC_CALLBACK_1(Level1Scene::onContactBegin, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

    return true;
}
void  Level1Scene::GoToHelloWorldScene(cocos2d::Ref* sender) {

    auto scene = HelloWorldScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void  Level1Scene::update(float dt)
{
    float newPosX = Level1Scene::mySprite->getPositionX() + (DirX);
    float newPosY = Level1Scene::mySprite->getPositionY() + (DirY);

    Level1Scene::mySprite->setPosition(newPosX, newPosY);
}

bool Level1Scene::onContactBegin(cocos2d::PhysicsContact& contact)
{
    PhysicsBody* a = contact.getShapeA()->getBody();
    PhysicsBody* b = contact.getShapeB()->getBody();


    // v�rifiez si le joueur entre en contact avec une pierre
    if ((a->getCollisionBitmask() == mySprite_COLLISION_BITMASK && b->getCollisionBitmask() == FIRE_COLLISION_BITMASK) ||
        (b->getCollisionBitmask() == mySprite_COLLISION_BITMASK && a->getCollisionBitmask() == FIRE_COLLISION_BITMASK))
    {
        // affichez la sc�ne de fin de jeu (game over) ici
        auto scene = GameOverScene1::createScene();
        Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
    }
    // v�rifiez si le joueur entre dans la porte
    if ((a->getCollisionBitmask() == mySprite_COLLISION_BITMASK && b->getCollisionBitmask() == DOOR_COLLISION_BITMASK) ||
        (b->getCollisionBitmask() == mySprite_COLLISION_BITMASK && a->getCollisionBitmask() == DOOR_COLLISION_BITMASK))
    {
        // affichez la sc�ne de victoire ici
        auto scene = Level2Scene::createScene();
        Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
    }

   

    return true;

}



void Level1Scene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
