#include "FivePower.h"

FivePower::FivePower()
{

}

FivePower::FivePower(D3DXVECTOR3 _position, eDirection _direction, eObjectID _objectID)
	: DynamicObject(_position, _direction, _objectID)
{
}

void FivePower::Initialize()
{
	m_Sprite = new CSpriteDx9(*SpriteManager::getInstance()->getSprite(eSpriteID::SPRITE_5_POWER));
	m_ObjectState = STATE_ALIVE_IDLE;
	m_Position.z = 1.0f;
}

void FivePower::UpdateAnimation()
{
}


void FivePower::UpdateCollision(CObjectDx9* checkingObject)
{
	if (!isDead)
	{
		IDDirection collideDirection = this->m_Collision->CheckCollision(this, checkingObject);
		if (collideDirection != IDDirection::DIR_NONE)
		{
			switch (checkingObject->getID())
			{
			case eObjectID::NINJA:
			{
				Ninja* temp = (Ninja*)checkingObject;
				if (temp->getObjectState() == eObjectState::STATE_NINJA_IDLE || temp->getObjectState() == STATE_NINJA_RUN)
				{
					isDead = true;
					temp->SetInvulnerable(true);
					temp->setItemNinja(eIDItem::ITEM_5_POWER);
					SoundManagerDx9::getInstance()->getSoundBuffer(eSoundID::SOUND_NINJA_COLLECT)->Play();
					CGlobal::skills += 5;
					this->m_ObjectState = STATE_DEATH;
				}
			}
			break;
			case eObjectID::TILE_BASE:
				if (collideDirection == IDDirection::DIR_TOP)
				{
					if (getPhysic()->getVelocity().y <= 0)
					{
						getPhysic()->setVelocity(D3DXVECTOR2(0.0f, 0.0f));
					}
				}
				break;
			default:
				break;
			}

		}
	}
}


void FivePower::UpdateMovement()
{
	m_Physic->UpdateMovement(&m_Position);
}

void FivePower::Update()
{
	if (m_ObjectState == STATE_DEATH)
	{
		if (isDead)
		{
			Release();
		}
	}
}

void FivePower::Render(SPRITEHANDLE spriteHandle)
{
	if (m_Sprite)
	{
		m_Sprite->Render(spriteHandle, getPositionVec2(), m_Sprite->getSpriteEffect(), m_Sprite->getRotate(), m_Sprite->getScale(), m_Position.z);
	}
}

void FivePower::Release()
{
	isDead = true;
	m_Sprite->Release();
	SAFE_DELETE(m_Sprite);
}

FivePower::~FivePower()
{

}
