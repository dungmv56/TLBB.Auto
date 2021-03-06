#include "Player.hpp"

#include <QFile>

#include "GameWindowInfo.hpp"

Player::Player(const GameWindowInfo* gameWindowInfo) :
  m_gameWindowInfo(gameWindowInfo)
{
}

QDebug operator<<(QDebug qdb, const Player& player)
{
  qdb << "Name: " << player.getName();
  qdb << "HP: " << player.getHp();
  qdb << "Max Hp: " << player.getMaxHp();
  qdb << "Hp Percent: " << player.getHpPercent();
  qdb << "Mp: " << player.getMp();
  qdb << "Max Mp: " << player.getMaxMp();
  qdb << "Mp Percent: " << player.getMpPercent();
  qdb << "MenpaiId: " << player.getMenpaiId();
  qdb << "MenpaiName: " << player.getMenpaiName();
  qdb << "Pos(x, y)" << player.getPosX() << "," << player.getPosY();
  qdb << "SceneId: " << player.getSceneId();
  qdb << "SceneName: " << player.getSceneName();

  return qdb;
}

QString Player::getName() const
{
//  std::vector<DWORD> adrs{
//    0x87C374,0xC,0x1DC,0x4,0x34
//    0x145EB34, 0xC, 0x1EC, 0x4, 0x3C
//  };

  QString name;
  name.resize(13);

//  for (int i = 0; i < name.size(); i++)
//  {
//    auto nameChar = m_gameWindowInfo->readMemory<char>(adrs);
//    name[i] = nameChar;
//    *(adrs.end()-1) += 0x1;
//  }

  return name;
}

int Player::getSceneId() const
{
  DWORD adr = 0xA8F060;
  int mapId = m_gameWindowInfo->readMemory<int>(adr);

  return mapId;
}

QString Player::getSceneName() const
{
  QFile sceneDefineEx(":/app_res/SceneDefineEx.txt");

  QString sceneName = "Empty";

  if (sceneDefineEx.open(QIODevice::ReadOnly))
  {
    int sceneId = this->getSceneId();

    // Pass 2 line
    sceneDefineEx.readLine();
    sceneDefineEx.readLine();

    while (!sceneDefineEx.atEnd())
    {
      QByteArray line = sceneDefineEx.readLine();
      auto lineArr = line.split('\t');

      if (sceneId == lineArr.at(0).toInt())
      {
        sceneName = lineArr.at(1);
        break;
      }
    }
    sceneDefineEx.close();
  }

  return sceneName;
}

int Player::getHp() const
{
  return m_gameWindowInfo->readMemory<int>(0x145EB34, 0xC, 0x1EC, 0x4, 0x2760);
}

int Player::getMaxHp() const
{
  return m_gameWindowInfo->readMemory<int>(0x145EB34, 0xC, 0x1EC, 0x4, 0x27D8);
}

float Player::getHpPercent() const
{
  float divide = static_cast<float>(this->getHp())
      /
      static_cast<float>(this->getMaxHp());
  return divide * 100;
}

int Player::getMp() const
{
  return m_gameWindowInfo->readMemory<int>(0x145EB34, 0xC, 0x1EC, 0x4, 0x2764);
}

int Player::getMaxMp() const
{
  return m_gameWindowInfo->readMemory<int>(0x145EB34, 0xC, 0x1EC, 0x4, 0x27DC);
}

float Player::getMpPercent() const
{
  float divide = static_cast<float>(this->getMp())
      /
      static_cast<float>(this->getMaxMp());
  return divide * 100;
}

int Player::getMenpaiId() const
{
  return m_gameWindowInfo->readMemory<int>(0x145EB34, 0xC, 0x1EC, 0x4, 0xF4);
}

QString Player::getMenpaiName() const
{
  int menpaiId = this->getMenpaiId();

  QString menpaiName;
  switch(menpaiId)
  {
    case 0:
      menpaiName = "";
      break;
    case 1:
      menpaiName = "";
      break;
    case 2:
      menpaiName = "Cai Bang";
      break;
    case 3:
      menpaiName = "";
      break;
    case 4:
      menpaiName = "";
      break;
    case 5:
      menpaiName = "";
      break;
    case 6:
      menpaiName = "";
      break;
    case 7:
      menpaiName = "";
      break;
    case 8:
      menpaiName = "";
      break;
    case 9:
      menpaiName = "Not Join Yet";
      break;
    case 10:
      menpaiName = "";
      break;
    case 11:
      menpaiName = "";
      break;
    default:
      menpaiName = "Not found";
  }

  return menpaiName;
}

Player::Position Player::getPosition() const
{
  Position pos;

  pos.x = this->getPosX();
  pos.y = this->getPosY();

  return pos;
}

float Player::getPosX() const
{
  return m_gameWindowInfo->readMemory<float>(0x145EA78, 0x5C);
}

float Player::getPosY() const
{
  return m_gameWindowInfo->readMemory<float>(0x145EA78, 0x64);
}

void Player::sendChatMsg(const QString& msg)
{
  m_gameWindowInfo->postMessage(WM_KEYDOWN, VK_RETURN, 0x1C0001);
  m_gameWindowInfo->postMessage(WM_KEYDOWN, VK_DOWN, 0x500001);
  for (int i = 0; i < msg.size(); i++)
  {
    m_gameWindowInfo->postMessage(WM_CHAR, msg.at(i).toLatin1(), 0);
  }
  m_gameWindowInfo->postMessage(WM_KEYDOWN, VK_RETURN, 0x1C0001);
  m_gameWindowInfo->postMessage(WM_KEYUP, VK_RETURN, 0x1C0001);
  m_gameWindowInfo->postMessage(WM_KEYDOWN, VK_RETURN, 0x1C0001);
  m_gameWindowInfo->postMessage(WM_KEYUP, VK_RETURN, 0x1C0001);
  m_gameWindowInfo->postMessage(WM_KEYDOWN, VK_RETURN, 0x1C0001);
  m_gameWindowInfo->postMessage(WM_KEYUP, VK_RETURN, 0x1C0001);
}
