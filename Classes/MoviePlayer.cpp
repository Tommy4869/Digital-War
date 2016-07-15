#include "MoviePlayer.h"
//#include "Director.h"

NS_CC_BEGIN

MoviePlayer * MoviePlayer::_instance = 0;

static char * videobuf = 0;

static void *lock(void *data, void **p_pixels)
{
	*p_pixels = videobuf;
	return NULL;
}

static void unlock(void *data, void *id, void *const *p_pixels)
{
	assert(id == NULL);
}

static void display(void *data, void *id)
{
	(void)data;
	assert(id == NULL);
}

MoviePlayer::MoviePlayer() :
vlc(0), vlc_player(0)
{
	init();
}

MoviePlayer::~MoviePlayer()
{
	CCSprite::~CCSprite();
	free(videobuf);

	libvlc_media_player_stop(vlc_player);
	libvlc_media_player_release(vlc_player);
	libvlc_release(vlc);
}

bool MoviePlayer::init(void)
{
	vlc = libvlc_new(0, NULL);
	vlc_player = libvlc_media_player_new(vlc);

	CCSize size = CCDirector::sharedDirector()->getWinSize();
	width = size.width;
	height = size.height;
	videobuf = (char *)malloc((width * height) << 2);
	memset(videobuf, 0, (width * height) << 2);
	libvlc_video_set_callbacks(vlc_player, lock, unlock, display, NULL);
	m_readyToShow = true;
	libvlc_video_set_format(vlc_player, "RGBA", width, height, width << 2);

	CCTexture2D *texture = new CCTexture2D();
	texture->initWithData(videobuf, sizeof(videobuf), kCCTexture2DPixelFormat_RGBA8888, width, height, size);//sizeof(videobuf)
	return initWithTexture(texture);
}

void MoviePlayer::play(char *path)
{
	m_readyToShow = false;
	libvlc_media_t *media = libvlc_media_new_path(vlc, path);
	libvlc_media_player_set_media(vlc_player, media);
	libvlc_media_release(media);
	libvlc_media_player_play(vlc_player);
}

void MoviePlayer::stop(void)
{
	libvlc_media_player_stop(vlc_player);
}

void MoviePlayer::pause(void)
{
	libvlc_media_player_pause(vlc_player);
}

void MoviePlayer::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags)
{
	_insideBounds = (flags & FLAGS_TRANSFORM_DIRTY) ? renderer->checkVisibility(transform, _contentSize) : _insideBounds;
	if (_insideBounds)
	{
		if (m_readyToShow) {
			m_readyToShow = false;
			Texture2D *texture = new Texture2D();
			texture->initWithData(m_videobuf,
				(width * height) << 2,
				Texture2D::PixelFormat::RGBA8888,
				width, height, Size(width, height));
			texture->autorelease();
			setTexture(texture);
		}
		QuadCommand a;
		a.init(_globalZOrder, _texture->getName(), getGLProgramState(), _blendFunc, &_quad, 1, transform);
		renderer->addCommand(&a);
#if CC_SPRITE_DEBUG_DRAW
		_debugDrawNode->clear();
		Vec2 vertices[4] = {
			Vec2(_quad.bl.vertices.x, _quad.bl.vertices.y),
			Vec2(_quad.br.vertices.x, _quad.br.vertices.y),
			Vec2(_quad.tr.vertices.x, _quad.tr.vertices.y),
			Vec2(_quad.tl.vertices.x, _quad.tl.vertices.y),
		};
		_debugDrawNode->drawPoly(vertices, 4, true, Color4F(1.0, 1.0, 1.0, 1.0));
#endif //CC_SPRITE_DEBUG_DRAW
	}
}


MoviePlayer * MoviePlayer::instance()
{
	if (_instance == 0)
		_instance = new MoviePlayer();
	return _instance;
}

NS_CC_END