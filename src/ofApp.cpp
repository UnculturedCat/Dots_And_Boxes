#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    players.push_back(Player(ofColor(255,0,0)));
    players.push_back(Player(ofColor(0,0,255)));
    currentBoxX = PAGE_PADDING;
    currentBoxY = PAGE_PADDING;
    int boxId = 0;
    for(int currentGridYPos = 0; currentGridYPos < GRID_SIZE; currentGridYPos++){
        for(int currentGridXPos = 0; currentGridXPos < GRID_SIZE; currentGridXPos++){
            boxes.push_back(Box(currentBoxX, currentBoxY, currentGridYPos == 0, currentGridXPos == 0, boxId));
            currentBoxX += BOX_SIZE;
            boxId++;
        }
        currentBoxX = PAGE_PADDING;
        currentBoxY += BOX_SIZE;
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
     ofBackground(255, 255, 255);
    
    ofSetColor(0, 0, 0);
    for(Box box : boxes){
        box.drawWalls();
    }
   
   
}

void ofApp::takeWall(){
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}


Box::Box(int xPos, int yPos, bool drawTWall, bool drawLWall, int id){
    xCoordinate = xPos;
    yCoordinate = yPos;
    drawTopWall = drawTWall;
    drawLeftWall = drawLWall;
    m_boxId = id;
    setUpWalls();
}

void Box::setUpWalls(){
    // //Draw top wall
    if(drawTopWall)
        m_walls.push_back(Wall(xCoordinate, yCoordinate, xCoordinate + BOX_SIZE, yCoordinate, m_boxId));

    // //Draw left wall
    if(drawLeftWall)
         m_walls.push_back(Wall(xCoordinate, yCoordinate, xCoordinate, yCoordinate + BOX_SIZE, m_boxId));

    //  Draw right wall
         m_walls.push_back(Wall(xCoordinate + BOX_SIZE, yCoordinate, xCoordinate + BOX_SIZE, yCoordinate + BOX_SIZE, m_boxId));

    //Draw bottom wall
         m_walls.push_back(Wall(xCoordinate, yCoordinate + BOX_SIZE, xCoordinate + BOX_SIZE, yCoordinate + BOX_SIZE, m_boxId)); 
}

void Box::drawWalls(){
    for(auto wall : m_walls){
        wall.draw();
    }
}

Player::Player(){
    m_playerColor.set(0,255,0);
}

Player::Player(ofColor playerColor){
    m_playerColor = playerColor;
}

Wall::Wall(int xPos, int yPos,int xPos2, int yPos2, int boxId) : m_xPos(xPos), m_yPos(yPos), m_xPos2(xPos2), m_yPos2(yPos2), m_boxId(boxId){
    m_color.set(0,0,0);
}

void Wall::draw(){
     ofDrawLine(m_xPos, m_yPos, m_xPos2, m_yPos2);
}