#pragma once

#include "ofMain.h"

#define PAGE_PADDING 50
#define GRID_SIZE 10
#define BOX_SIZE 50



class Wall{

	public:
		int m_xPos, m_yPos, m_xPos2, m_yPos2, m_boxId;
		ofColor m_color;
		
		vector<int> parentBoxesId;
		bool taken;

		Wall(int xPos, int yPos,int xPos2, int yPos2, int boxId);
		void draw();
		void setWallAsTaken();
};

class Box{
	public:
		Box(int xPos, int yPos, bool drawTWall, bool drawLWall, int boxId);

		int xCoordinate;
		int yCoordinate;
		int numberOfWallsTaken;
		int m_boxId;
		bool taken;
		bool drawTopWall;
		bool drawLeftWall;

		ofRectangle m_boxRectangle;
		ofColor m_boxTakenColor;

		vector<Wall> m_walls;

		void setUpWalls();
		void drawWalls();
		void increaseTakenWalls();
};

class Grid{

};

class Player{
	public:
		ofColor m_playerColor;
		vector<Box> m_takenBoxes;

		Player();
		Player(ofColor playerColor);
};

class ofApp : public ofBaseApp{

	public:
		bool m_gameFinished;
		int currentBoxX;
		int currentBoxY;
		Player currentPlayer;
		vector<Player> players;
		vector<Box> boxes;

		void setup();
		void update();
		void draw();

		void takeWall();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);

		
};