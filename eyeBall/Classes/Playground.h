#ifndef __PLAYGROUND_H__
#define __PLAYGROUND_H__

#include "cocos2d.h"
#include "Entity.h"

class Playground : public cocos2d::CCLayer
{
public:
	virtual bool init();  
	static cocos2d::CCScene* scene();

	LAYER_NODE_FUNC(HelloWorld);

private:
  void update(cocos2d::ccTime dt);

private:
  Entity *m_background;
  Entity *m_eyeBall;
};

#endif
