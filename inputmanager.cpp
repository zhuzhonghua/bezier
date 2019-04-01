#include "stdafx.h"

#include "inputmanager.h"

InputManager::InputManager()
{
}

void InputManager::update()
{
  _previousKeys.clear();
  std::unordered_map<unsigned int, bool>::iterator itr = _keys.begin();
  for (; itr != _keys.end(); itr++)
  {
    _previousKeys[itr->first] = itr->second;
  }
}
void InputManager::pressKey(unsigned int key)
{
  _keys[key] = true;
}
void InputManager::releaseKey(unsigned int key)
{
  _keys[key] = false;
}

void InputManager::setMouseCoords(float x, float y)
{
  _mouseCoords = Point((int)x, (int)y);
}

bool InputManager::isKeyDown(unsigned int key)
{
  std::unordered_map<unsigned int, bool>::iterator itr = _keys.find(key);
  if (itr != _keys.end())
  {
    return itr->second;
  }
  else
  {
    return false;
  }
}

bool InputManager::isKeyPressed(unsigned int key)
{
  if (isKeyDown(key) == true && wasKeyDown(key) == false){
    return true;
  }

  return false;
}

bool InputManager::wasKeyDown(unsigned int key)
{
  std::unordered_map<unsigned int, bool>::iterator itr = _previousKeys.find(key);
  if (itr != _previousKeys.end()){
    return itr->second;
  }
  else{
    return false;
  }
}
