#ifndef __MOVIEPLAYER_H__
#define __MOVIEPLAYER_H__

/****************************************************************************
http://www.cnblogs.com/evan-cai/

Author: Evan-Cai
Date: 2013-01-25
****************************************************************************/

#include <vlc\vlc.h>
#include "cocos2d.h"

NS_CC_BEGIN

class MoviePlayer : public CCSprite
{
public:
	~MoviePlayer();

	static MoviePlayer * instance(void);

	bool init(void);
	void play(char *path);
	void stop(void);
	void pause(void);
	virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags) override;


protected:
	MoviePlayer();

private:

	libvlc_instance_t *vlc;
	libvlc_media_player_t *vlc_player;

	unsigned int width;
	unsigned int height;

	bool m_readyToShow;

	char *m_videobuf;
	

	static MoviePlayer * _instance;
};

NS_CC_END

#endif