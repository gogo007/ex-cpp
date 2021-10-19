/*
#include <QtTest>
#include "../game.cpp"
#include "../player.cpp"
#include "../state.cpp"
#include "../mortstate.cpp"
#include "../faiblestate.cpp"
#include "../moyenstate.cpp"
#include "../bonstate.cpp"
#include "../fortstate.cpp"
#include <string>
#include <typeinfo>
#include <iostream>
// add necessary includes here

class testWarOfRobots : public QObject
{
    Q_OBJECT

public:
    testWarOfRobots();
    ~testWarOfRobots();

private slots:
    void testGetPseudoPlayer();
    void testRegenPlayer();
    void testSetLifePlayer();
    void testSetStatePlayer();
    void testAttackPlayer();
    void testDefendPlayer();
    void testSearchPlayer();
};

testWarOfRobots::testWarOfRobots()
{

}

testWarOfRobots::~testWarOfRobots()
{

}
/*
/*    TEST CLASS PLAYER     */
/*
void testWarOfRobots::testGetPseudoPlayer()
{
    std::string s="jean";
    Player *p = new Player(s);
    QCOMPARE(p->getPseudo(),"jean");
}

void testWarOfRobots::testRegenPlayer(){

    Player *p = new Player("abon");
    p->setLife(60);
    p->regen();
    bool isTrue=(p->getLife()>=60);
    QCOMPARE(isTrue,true);
}
void testWarOfRobots::testSetLifePlayer(){

    Player *p = new Player("abon");
    p->setLife(60);
    QCOMPARE(60,p->getLife());
}
void testWarOfRobots::testSetStatePlayer(){

    Player *pSta = new Player("abon");
    pSta->setState(new BonState);
    QCOMPARE((const char *)typeid( *(pSta->getState())).name(),(const char *)"8BonState");
}
void testWarOfRobots::testAttackPlayer(){

    Player *pA = new Player("a");
    Player *pSA = new Player("b");
    pA->attack(pSA,10);
    QCOMPARE(pA->getLife(),90);
}
void testWarOfRobots::testDefendPlayer(){

    Player *pD = new Player("c");
    Player *pDS = new Player("d");
    pD->attack(pDS,10);
    QCOMPARE(pDS->getLife(),89);
}
void testWarOfRobots::testSearchPlayer(){
    Game * aG=new Game(3);
    Player *pA = new Player("A");
    Player *pSA = new Player("B");
    Player *pD = new Player("C");

    aG->addPlayer(pA);
    aG->addPlayer(pSA);
    aG->addPlayer(pD);
    std::string result = aG->searchPlayer("C")->getPseudo();
    QCOMPARE("C",result);
}
QTEST_MAIN(testWarOfRobots)

#include "tst_testwarofrobots.moc"
*/