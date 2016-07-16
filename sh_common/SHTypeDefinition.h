#pragma once

#include <memory>
#include <weak_raw_ptr.hpp>

#include "Position.h"

namespace SH
{

typedef INT CARD_INDEX;

struct DecideAction
{
	enum Type
	{
		NONE = -1,
		ATTACK = 0, // Attack
		MOVE = 1, // Move
		GUARD = 2, // Guard
		DEFENSE = 3, // Defense
		ESCAPE = 4, // Escape
	};
};

struct DecideVariable
{
	enum type
	{
		NONE = -1,
		RANDOM = 0, // 랜덤
		HP = 1, // HP
		DISTANCE = 2, // 거리
		TARGETING = 3, // 타게팅
		COST = 4, // 코스트
		CLASS = 5, // 클래스
	};
};

struct DecideTargeting
{
	enum type
	{
		NONE = 0,
		HIGH = 1, // 높은 값의 타겟을 지정함
		LOW = 2, // 낮은 값의 타겟을 지정함
		MORE_THAN = 3, // 나보다 높은 값을 가진 타겟을 지정
		LESS_THAN = 4, // 나보다 낮은 값을 가진 타겟을 지정
		SIMILAR = 5, // 나와 비슷한 값을 가진 타겟을 지정
		SAME = 6, // 일치하는 값을 가진 타겟을 지정
	};
};

struct TEAM
{
	enum type
	{
		NONE = -1,
		RED = 0,
		BLUE = 1,
		MAX,
	};
};

const int TURN_UNIT = 200; // 200ms

const int MAX_CORPS_CARD = 16;
const int MAX_SQUAD_CARD = 11;

const int MAX_DECK = 16;

class Turn;
typedef std::unique_ptr<Turn> UNIQUE_TURN;
typedef light::weak_raw_ptr<Turn> WEAK_TURN;

class Action;
typedef std::shared_ptr<Action> SHARED_ACTION; 
typedef std::unique_ptr<Action> UNIQUE_ACTION;
typedef light::weak_raw_ptr<Action> WEAK_ACTION;

class Decide;
typedef std::unique_ptr<Decide> UNIQUE_DECIDE;
typedef light::weak_raw_ptr<Decide> WEAK_DECIDE;

class Corps;
typedef std::unique_ptr<Corps> UNIQUE_CORPS;
typedef light::weak_raw_ptr<Corps> WEAK_CORPS;

typedef std::vector<WEAK_CORPS> VECTOR_CORPS;
typedef std::unique_ptr< VECTOR_CORPS > UNIQUE_VECTOR_CORPS;
typedef light::weak_raw_ptr< VECTOR_CORPS > WEAK_VECTOR_CORPS;

class Map;
typedef std::unique_ptr<Map> UNIQUE_MAP;
typedef light::weak_raw_ptr<Map> WEAK_MAP;

class Card;
typedef std::shared_ptr<Card> SHARED_CARD;
typedef std::unique_ptr<Card> UNIQUE_CARD;
typedef light::weak_raw_ptr<Card> WEAK_CARD;

class Player;

typedef std::shared_ptr<Player> SHARED_PLAYER;
typedef std::unique_ptr<Player> UNIQUE_PLAYER;
typedef light::weak_raw_ptr<Player> WEAK_PLAYER;

class Squad;
typedef std::unique_ptr<Squad> UNIQUE_SQUAD;
typedef light::weak_raw_ptr<Squad> WEAK_SQUAD;

typedef std::vector<WEAK_SQUAD> VECTOR_SQUAD;
typedef std::unique_ptr< VECTOR_SQUAD > UNIQUE_VECTOR_SQUAD;
typedef light::weak_raw_ptr< VECTOR_SQUAD > WEAK_VECTOR_SQUAD;

class Game;
typedef std::unique_ptr<Game> UNIQUE_GAME;
typedef light::weak_raw_ptr<Game> WEAK_GAME;

class Ball;
typedef std::unique_ptr<Ball> UNIQUE_BALL;
typedef light::weak_raw_ptr<Ball> WEAK_BALL;

} // namespace SH

namespace ExcelData
{

class Character;
typedef std::unique_ptr<Character> UNIQUE_CHARACTER;
typedef light::weak_raw_ptr<Character> WEAK_CHARACTER;

} // namespace ExcelData