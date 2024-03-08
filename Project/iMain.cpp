#include "iGraphics.h"
#include <curl/curl.h>
#include <time.h>
#include <string.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <array>


int x = 300, y = 300, r = 20;
int circleX = 200;
int circleY = 200;
int screenWidth = 1280;
int screenHeight = 720;
bool screenClicked = false;
bool nextpageClick = false;
int rankClick = false;
int homepageclick = false;
int i = 1;
int newscheck = 0;
char usersignup[100],usersignup1[100],passsignup[100],passingup2[100],user[100],user2[100],password[100],password2[100];
int len,mode;
int signuser=0,uuser=0;
int signuser_len=0,signpass_len=0;
int user_len=0,pass_len=0;
int login=0;
int MAX_LENGTH=1000;
int match=0;
int wrong=0;

/*
	function iDraw() is called again and again by the system.
		iSetColor(24
		9, 249, 249);
		iFilledRectangle(90, 450, 285, 190);
		iFilledRectangle(450, 450, 285, 190);
		iFilledRectangle(810, 450, 285, 190);
		iSetColor(0, 0, 0);

		i=0;
	if (sc==1)
	{
		iShowBMP(0, 0, "loading.bmp");
		sc++;
	}

		if (screenClicked)
	{
		iClear();
		i++;
		iShowBMP(0, 0, "home.bmp");

	}
	if (isRanking)
		{
			iClear();
			iShowBMP(0, 0, "rankings.bmp");
		}
		if (ishome)
		{
			iClear();
			iShowBMP(0, 0, "loading.bmp");
		}
	}

	*/

char introimages[134][26] = {
	"Intro/ezgif-frame-001.bmp",
	"Intro/ezgif-frame-002.bmp",
	"Intro/ezgif-frame-003.bmp",
	"Intro/ezgif-frame-004.bmp",
	"Intro/ezgif-frame-005.bmp",
	"Intro/ezgif-frame-006.bmp",
	"Intro/ezgif-frame-007.bmp",
	"Intro/ezgif-frame-008.bmp",
	"Intro/ezgif-frame-009.bmp",
	"Intro/ezgif-frame-010.bmp",
	"Intro/ezgif-frame-011.bmp",
	"Intro/ezgif-frame-012.bmp",
	"Intro/ezgif-frame-013.bmp",
	"Intro/ezgif-frame-014.bmp",
	"Intro/ezgif-frame-015.bmp",
	"Intro/ezgif-frame-016.bmp",
	"Intro/ezgif-frame-017.bmp",
	"Intro/ezgif-frame-018.bmp",
	"Intro/ezgif-frame-019.bmp",
	"Intro/ezgif-frame-020.bmp",
	"Intro/ezgif-frame-021.bmp",
	"Intro/ezgif-frame-022.bmp",
	"Intro/ezgif-frame-023.bmp",
	"Intro/ezgif-frame-024.bmp",
	"Intro/ezgif-frame-025.bmp",
	"Intro/ezgif-frame-026.bmp",
	"Intro/ezgif-frame-027.bmp",
	"Intro/ezgif-frame-028.bmp",
	"Intro/ezgif-frame-029.bmp",
	"Intro/ezgif-frame-030.bmp",
	"Intro/ezgif-frame-031.bmp",
	"Intro/ezgif-frame-032.bmp",
	"Intro/ezgif-frame-033.bmp",
	"Intro/ezgif-frame-034.bmp",
	"Intro/ezgif-frame-035.bmp",
	"Intro/ezgif-frame-036.bmp",
	"Intro/ezgif-frame-037.bmp",
	"Intro/ezgif-frame-038.bmp",
	"Intro/ezgif-frame-039.bmp",
	"Intro/ezgif-frame-040.bmp",
	"Intro/ezgif-frame-041.bmp",
	"Intro/ezgif-frame-042.bmp",
	"Intro/ezgif-frame-043.bmp",
	"Intro/ezgif-frame-044.bmp",
	"Intro/ezgif-frame-045.bmp",
	"Intro/ezgif-frame-046.bmp",
	"Intro/ezgif-frame-047.bmp",
	"Intro/ezgif-frame-048.bmp",
	"Intro/ezgif-frame-049.bmp",
	"Intro/ezgif-frame-050.bmp",
	"Intro/ezgif-frame-051.bmp",
	"Intro/ezgif-frame-052.bmp",
	"Intro/ezgif-frame-053.bmp",
	"Intro/ezgif-frame-054.bmp",
	"Intro/ezgif-frame-055.bmp",
	"Intro/ezgif-frame-056.bmp",
	"Intro/ezgif-frame-057.bmp",
	"Intro/ezgif-frame-058.bmp",
	"Intro/ezgif-frame-059.bmp",
	"Intro/ezgif-frame-060.bmp",
	"Intro/ezgif-frame-061.bmp",
	"Intro/ezgif-frame-062.bmp",
	"Intro/ezgif-frame-063.bmp",
	"Intro/ezgif-frame-064.bmp",
	"Intro/ezgif-frame-065.bmp",
	"Intro/ezgif-frame-066.bmp",
	"Intro/ezgif-frame-067.bmp",
	"Intro/ezgif-frame-068.bmp",
	"Intro/ezgif-frame-069.bmp",
	"Intro/ezgif-frame-070.bmp",
	"Intro/ezgif-frame-071.bmp",
	"Intro/ezgif-frame-072.bmp",
	"Intro/ezgif-frame-073.bmp",
	"Intro/ezgif-frame-074.bmp",
	"Intro/ezgif-frame-075.bmp",
	"Intro/ezgif-frame-076.bmp",
	"Intro/ezgif-frame-077.bmp",
	"Intro/ezgif-frame-078.bmp",
	"Intro/ezgif-frame-079.bmp",
	"Intro/ezgif-frame-080.bmp",
	"Intro/ezgif-frame-081.bmp",
	"Intro/ezgif-frame-082.bmp",
	"Intro/ezgif-frame-083.bmp",
	"Intro/ezgif-frame-084.bmp",
	"Intro/ezgif-frame-085.bmp",
	"Intro/ezgif-frame-086.bmp",
	"Intro/ezgif-frame-086.bmp",
	"Intro/ezgif-frame-087.bmp",
	"Intro/ezgif-frame-088.bmp",
	"Intro/ezgif-frame-089.bmp", "Intro/ezgif-frame-090.bmp", "Intro/ezgif-frame-091.bmp", "Intro/ezgif-frame-092.bmp", "Intro/ezgif-frame-093.bmp", "Intro/ezgif-frame-094.bmp", "Intro/ezgif-frame-095.bmp", "Intro/ezgif-frame-096.bmp", "Intro/ezgif-frame-097.bmp", "Intro/ezgif-frame-098.bmp", "Intro/ezgif-frame-099.bmp", "Intro/ezgif-frame-100.bmp", "Intro/ezgif-frame-101.bmp", "Intro/ezgif-frame-102.bmp", "Intro/ezgif-frame-103.bmp", "Intro/ezgif-frame-104.bmp", "Intro/ezgif-frame-105.bmp", "Intro/ezgif-frame-106.bmp", "Intro/ezgif-frame-107.bmp", "Intro/ezgif-frame-108.bmp", "Intro/ezgif-frame-109.bmp", "Intro/ezgif-frame-110.bmp", "Intro/ezgif-frame-111.bmp", "Intro/ezgif-frame-112.bmp", "Intro/ezgif-frame-113.bmp", "Intro/ezgif-frame-114.bmp", "Intro/ezgif-frame-115.bmp", "Intro/ezgif-frame-116.bmp", "Intro/ezgif-frame-117.bmp", "Intro/ezgif-frame-118.bmp", "Intro/ezgif-frame-119.bmp", "Intro/ezgif-frame-120.bmp", "Intro/ezgif-frame-121.bmp", "Intro/ezgif-frame-122.bmp", "Intro/ezgif-frame-123.bmp", "Intro/ezgif-frame-124.bmp", "Intro/ezgif-frame-125.bmp", "Intro/ezgif-frame-126.bmp", "Intro/ezgif-frame-127.bmp", "Intro/ezgif-frame-128.bmp", "Intro/ezgif-frame-129.bmp", "Intro/ezgif-frame-130.bmp", "Intro/ezgif-frame-131.bmp", "Intro/ezgif-frame-132.bmp"};
int introimage = 0;

char homepageimage[4][22] = {"introAnimation/19.bmp", "introAnimation/20.bmp",
							 "introAnimation/21.bmp", "introAnimation/22.bmp"};
int homepage = 0;
char changescore[17][22]{
	"introAnimation/23.bmp", "introAnimation/24.bmp", "introAnimation/25.bmp", "introAnimation/26.bmp", "introAnimation/27.bmp", "introAnimation/28.bmp", "introAnimation/29.bmp", "introAnimation/30.bmp", "introAnimation/31.bmp", "introAnimation/32.bmp", "introAnimation/33.bmp", "introAnimation/34.bmp", "introAnimation/35.bmp", "introAnimation/36.bmp", "introAnimation/37.bmp", "introAnimation/38.bmp", "introAnimation/39.bmp"

};
char rankingimage[2][22]{
	"introAnimation/40.bmp", "introAnimation/41.bmp"};

int rankimg = 0;

char home_slide_images[6][34]{
	"introAnimation/slide/slide_1.bmp", "introAnimation/slide/slide_2.bmp", "introAnimation/slide/slide_3.bmp", "introAnimation/slide/slide_4.bmp",
	"introAnimation/slide/slide_5.bmp", "introAnimation/slide/slide_6.bmp"};
int slide_image = 0;

int scoreboard = 0;
int flag1 = 0, flag2 = 0, flag3 = 0;
void introanimation()
{
	if (introimage == 132)
	{
		iShowBMP(0, 0, introimages[131]);
	}
	else
	{
		introimage++;
		Sleep(12);
		iShowBMP(0, 0, introimages[introimage]);
	}
}
// void mainscreen(){
// 	iShowBMP(0, 0, homepageimage[3]);

// }

int home = 0;

void newspage()
{

	iShowBMP(0, 0, "introAnimation/NewsPage.bmp");
}
void nextpage()
{
	nextpageClick = true;
}
void homescreen()
{
	iShowBMP(0, 0, "introAnimation/Home.bmp");
}
char query[100],query1[100];
// void ASKAI()
// {
// 	iShowBMP(0, 0, "introAnimation/leagues.bmp");
// 	if(mode==3){
// 		iSetColor(0,0,0);
// 		iText(315,61,query,GLUT_BITMAP_HELVETICA_18);
// 	}
// }
void leagues(){
	iShowBMP(0, 0, "introAnimation/leagues.bmp");
}

void statspage_testteam_data()
{
	std::ifstream inputFile("test_team_rankings.txt");

	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file." << std::endl;
		return;
	}

	std::string line;
	int yCoordinate = 505;
	while (std::getline(inputFile, line))
	{
		iSetColor(0, 0, 0);
		iText(90, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_9_BY_15);
		yCoordinate -= 53;
	}

	inputFile.close();
}

void statspage_oditeam_data()
{
	std::ifstream inputFile("team_rankings.txt");

	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file." << std::endl;
		return;
	}

	std::string line;
	int yCoordinate = 505;
	while (std::getline(inputFile, line))
	{
		iSetColor(0, 0, 0);
		iText(512, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_9_BY_15);
		yCoordinate -= 53;
	}

	inputFile.close();
}
void t20team(){
	std::ifstream inputFile("rankings/t20teamranking.txt");

	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file." << std::endl;
		return;
	}

	std::string line;
	int yCoordinate = 505;
	while (std::getline(inputFile, line))
	{
		iSetColor(0, 0, 0);
		iText(960, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_9_BY_15);
		yCoordinate -= 53;
	}

	inputFile.close();
}
void test_bat(){
	std::ifstream inputFile("rankings/testbat.txt");

	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file." << std::endl;
		return;
	}

	std::string line;
	int yCoordinate = 505;
	while (std::getline(inputFile, line))
	{
		iSetColor(0, 0, 0);
		iText(90, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_9_BY_15);
		yCoordinate -= 53;
	}

	inputFile.close();
}
void odi_bat()
{
	std::ifstream inputFile("rankings/odibat.txt");

	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file." << std::endl;
		return;
	}

	std::string line;
	int yCoordinate = 505;
	while (std::getline(inputFile, line))
	{
		iSetColor(0, 0, 0);
		iText(512, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_9_BY_15);
		yCoordinate -= 53;
	}

	inputFile.close();
}
void t20_bat(){
	std::ifstream inputFile("rankings/t20bat.txt");

	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file." << std::endl;
		return;
	}

	std::string line;
	int yCoordinate = 505;
	while (std::getline(inputFile, line))
	{
		iSetColor(0, 0, 0);
		iText(960, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_9_BY_15);
		yCoordinate -= 53;
	}

	inputFile.close();
}
void odi_bowl(){
	std::ifstream inputFile("rankings/odibowl.txt");

	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file." << std::endl;
		return;
	}

	std::string line;
	int yCoordinate = 505;
	while (std::getline(inputFile, line))
	{
		iSetColor(0, 0, 0);
		iText(90, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_9_BY_15);
		yCoordinate -= 53;
	}

	inputFile.close();
}
void test_bowl(){
	std::ifstream inputFile("rankings/testbowl.txt");

	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file." << std::endl;
		return;
	}

	std::string line;
	int yCoordinate = 505;
	while (std::getline(inputFile, line))
	{
		iSetColor(0, 0, 0);
		iText(512, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_9_BY_15);
		yCoordinate -= 53;
	}

	inputFile.close();
}
void t20_bowl(){
	std::ifstream inputFile("rankings/t20bowl.txt");

	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file." << std::endl;
		return;
	}

	std::string line;
	int yCoordinate = 505;
	while (std::getline(inputFile, line))
	{
		iSetColor(0, 0, 0);
		iText(960, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_9_BY_15);
		yCoordinate -= 53;
	}

	inputFile.close();
}

void scorecard()
{
	std::ifstream inputFile("score.txt");

	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file." << std::endl;
		return;
	}

	std::string line;
	int yCoordinate = 628;
	while (std::getline(inputFile, line))
	{
		iSetColor(0, 0, 0);
		if (yCoordinate == 628 || yCoordinate == 580 || yCoordinate == 496)
		{
			iText(60, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_9_BY_15);
		}
		else
		{
			iText(60, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_18);
		}

		yCoordinate -= 12;
	}

	inputFile.close();
}

void news()
{
	std::ifstream inputFile("news_info.txt");

	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file." << std::endl;
		return;
	}

	std::string line;
	int yCoordinate = 346;
	while (std::getline(inputFile, line))
	{
		iSetColor(0, 0, 0);
		if (yCoordinate == 334)
		{
			iText(441, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_9_BY_15);
		}
		else if (yCoordinate == 346)
		{
			iText(441, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_18);
		}
		else
		{
			iText(441, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_9_BY_15);
		}

		yCoordinate -= 12;
	}

	inputFile.close();
}
bool iDoesFileExist(const char *filename)
{
	std::ifstream file(filename);
	return file.good();
}
char newsimage[3][13] = {"1_image.bmp", "2_image.bmp", "3_image.bmp"};
void surfacenews_images()
{
	if (iDoesFileExist(newsimage[0]))
	{
		iShowBMP(100, 405, newsimage[0]);
	}
	else
	{
		iShowBMP(100, 76, "1_imagecopy.bmp");
	}

	if (iDoesFileExist(newsimage[1]))
	{
		iShowBMP(100, 250, newsimage[1]);
	}
	else
	{
		iShowBMP(100, 76, "1_imagecopy.bmp");
	}

	if (iDoesFileExist(newsimage[2]))
	{
		iShowBMP(100, 76, newsimage[2]);
	}
	else
	{
		iShowBMP(100, 76, "1_imagecopy.bmp");
	}
}

void surfacenews()
{
	int first_news = 520, second_news = 365, third_news;
	std::ifstream inputFile("sports_articles.txt");

	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file." << std::endl;
		return;
	}

	std::string line;
	int yCoordinate = 520;
	while (std::getline(inputFile, line))
	{
		iSetColor(0, 0, 0);
		switch (yCoordinate)
		{
		case 520:
			iText(326, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_18);
			yCoordinate -= 30;
			break;
		case 490:
			iText(326, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_9_BY_15);
			yCoordinate -= 20;
			break;
		case 470:
			iText(326, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);
			yCoordinate -= 20;
			break;
		case 450:
			iText(326, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);
			yCoordinate -= 88;
			break;
		case 362:
			iText(326, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_18);
			yCoordinate -= 30;
			break;
		case 332:
			iText(326, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_9_BY_15);
			yCoordinate -= 20;
			break;
		case 312:
			iText(326, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);
			yCoordinate -= 20;
			break;
		case 292:
			iText(326, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);
			yCoordinate -= 107;
			break;
		case 185:
			iText(326, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_18);
			yCoordinate -= 30;
			break;
		case 155:
			iText(326, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_9_BY_15);
			yCoordinate -= 20;
			break;
		case 135:
			iText(326, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);
			yCoordinate -= 20;
			break;
		case 115:
			iText(326, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);
			yCoordinate -= 107;
			break;
		default:
			break;
		}
	}

	inputFile.close();
}
void mostread_news()
{
	std::ifstream inputFile("article_titles.txt");

	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file." << std::endl;
		return;
	}

	std::string line;
	int yCoordinate = 583;
	while (std::getline(inputFile, line))
	{
		iSetColor(0, 0, 0);

		iText(1054, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);
		yCoordinate -= 15;
	}

	inputFile.close();
}
void home_mostread_news()
{
	std::ifstream inputFile("home_most_read.txt");

	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file." << std::endl;
		return;
	}

	std::string line;
	int yCoordinate = 640;
	while (std::getline(inputFile, line))
	{
		iSetColor(0, 0, 0);

		iText(1020, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);
		yCoordinate -= 15;
	}

	inputFile.close();
}
void statsPage()
{

	iShowBMP(0, 0, "introAnimation/stats_main.bmp");
}
void batsman_ranking(){
	iShowBMP(0,0,"introAnimation/batsman_ranking.bmp");
}
void bowler_ranking(){
	iShowBMP(0,0,"introAnimation/Bowler_ranking.bmp");
}

// void ranking()
// {

// 		iShowBMP(0, 0, rankingimage[0]);

// 		iShowBMP(0, 0, rankingimage[1]);
// 		rankClick=false;

// }

void newscoreboard()
{

	if (scoreboard == 17)
	{
		iShowBMP(0, 0, changescore[16]);
		nextpageClick = false;
		scoreboard = 0;
	}
	else
	{
		scoreboard++;
		Sleep(100);
		iShowBMP(0, 0, changescore[scoreboard]);
	}
	printf("%d\n", scoreboard);
}
void detailnews_1()
{
	iShowBMP(0, 0, "introAnimation/Detail-News.bmp");
	iShowBMP(95, 371, "detailnews/1_image.bmp");
	std::ifstream inputFile("detailnews/sports_articles.txt");

	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file." << std::endl;
		return;
	}

	std::string line;
	int yCoordinate = 556;
	while (std::getline(inputFile, line))
	{
		iSetColor(0, 0, 0);
		if (yCoordinate == 556 || yCoordinate == 536)
		{
			iText(442, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_18);
			yCoordinate -= 20;
		}
		else if (yCoordinate == 516)
		{
			iText(441, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_9_BY_15);
			yCoordinate -= 40;
		}
		else if (yCoordinate == 476 || yCoordinate == 456)
		{
			iText(441, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);
			yCoordinate -= 20;
		}
		else if (yCoordinate == 436)
		{
			iText(441, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);
			yCoordinate -= 100;
		}
		else
		{
			iText(105, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);
			yCoordinate -= 20;
		}
	}

	inputFile.close();
}
void detailnews_2()
{
	std::ifstream inputFile("detailnews/sports_articles.txt");

	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file." << std::endl;
		return;
	}

	std::string line;
	int blankLineCount = 0;

	while (std::getline(inputFile, line) && blankLineCount < 4)
	{
		if (line.empty())
		{
			blankLineCount++;
		}
		else
		{
			blankLineCount = 0;
		}
		int y = 436;
		if (y == 436 && blankLineCount <= 4)
		{
			iText(105, y, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);
			y = 0;
		}
	}

	inputFile.close();
}

void homepagenews()
{
	if (iDoesFileExist("homenews/1_image.bmp"))
	{
		iShowBMP(55, 135, "homenews/1_image.bmp");
	}
	else
	{
		iShowBMP(100, 76, "1_imagecopy.bmp");
	}
	std::ifstream inputFile("homenews/sports_articles.txt");

	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file." << std::endl;
		return;
	}

	std::string line;
	int yCoordinate = 348;
	while (std::getline(inputFile, line))
	{
		iSetColor(0, 0, 0);
		if (yCoordinate == 348 || yCoordinate == 328)
		{
			iText(441, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_18);
			yCoordinate -= 20;
		}
		else if (yCoordinate == 308)
		{
			iText(441, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);
			yCoordinate -= 15;
		}
		else
		{
			iText(442, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_9_BY_15);
			yCoordinate -= 15;
		}
	}

	inputFile.close();
}
int next_click=0;
void livescore_1()

{
	char fimage[18];
	char simage[18];
	if (next_click == 0) {
        strcpy(fimage, "livescore/1_1.bmp");
		strcpy(simage, "livescore/2_2.bmp");
    } else if (next_click == 1) {
        strcpy(fimage, "livescore/7_7.bmp");
		strcpy(simage, "livescore/8_8.bmp");
    }
	if (iDoesFileExist(fimage))
	{
	iShowBMP(41,596,fimage);
	}
	else
	{
		iShowBMP(100, 76, "1_imagecopy.bmp");
	}
	if (iDoesFileExist(simage))
	{
	iShowBMP(41,546,simage);
	}
	else
	{
		iShowBMP(100, 76, "1_imagecopy.bmp");
	}
	char txtname[30];

    if (next_click == 0) {
        strcpy(txtname, "livescore/match_details_1.txt");
    } else if (next_click == 1) {
        strcpy(txtname, "livescore/match_details_4.txt");
    }

	std::ifstream inputFile(txtname);

	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file." << std::endl;
		return;
	}

	std::string line;
	int yCoordinate = 636;
	int pri = 0;
	int prim = 0;
	while (std::getline(inputFile, line))
	{
		iSetColor(0, 0, 0);
		if (yCoordinate == 636)
		{
			iText(55, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);

			yCoordinate -= 40;
		}
		else if (yCoordinate == 596)
		{
			iText(72, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_18);
			yCoordinate -= 50;
		}
		else if (yCoordinate == 546)
		{
			size_t vPosition = line.find("v");
			if (vPosition != std::string::npos)
			{
				 size_t startPos = vPosition + 2; 
            size_t endPos = std::min(startPos + 5, line.length());
            std::string textAfterV = line.substr(startPos, endPos - startPos);
            
            
            iText(72, yCoordinate, const_cast<char*>(textAfterV.c_str()), GLUT_BITMAP_HELVETICA_18);
			    yCoordinate -= 25;

			}
			else{
			
			iText(72, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_18);
			yCoordinate -= 25;
			}

		}
		else if (yCoordinate == 521)
		{
			iText(42, 526, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);
			yCoordinate -= 25;
			pri = 1;
			prim = 1;
		}
	}

	inputFile.close();

	
}
void livescore_2(){
	char fimage[22];
	char simage[22];

	if (next_click == 0) {
        strcpy(fimage, "livescore/3_3.bmp");
		strcpy(simage, "livescore/4_4.bmp");
    } else if (next_click == 1) {
        strcpy(fimage, "livescore/9_9.bmp");
		strcpy(simage, "livescore/10_10.bmp");
    }
	if (iDoesFileExist(fimage))
	{
	iShowBMP(361,596,fimage);
	}
	else
	{
		iShowBMP(100, 76, "1_imagecopy.bmp");
	}
	if (iDoesFileExist(simage))
	{
	iShowBMP(361,546,simage);
	}
	else
	{
		iShowBMP(100, 76, "1_imagecopy.bmp");
	}

	
	char txtname[30];
	  if (next_click == 0) {
        strcpy(txtname, "livescore/match_details_2.txt");
    } else if (next_click == 1) {
        strcpy(txtname, "livescore/match_details_5.txt");
    }

	
	std::ifstream inputFile(txtname);

	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file." << std::endl;
		return;
	}

	std::string line;
	int yCoordinate = 636;

	while (std::getline(inputFile, line))
	{
		iSetColor(0, 0, 0);
		if (yCoordinate == 636)
		{
			iText(378, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);

			yCoordinate -= 40;
		}
		else if (yCoordinate == 596)
		{
			iText(395, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_18);
			yCoordinate -= 50;
		}
		else if (yCoordinate == 546)
		{
			size_t vPosition = line.find("v");
			if (vPosition != std::string::npos)
			{
				 size_t startPos = vPosition + 2; 
            size_t endPos = std::min(startPos + 5, line.length());
            std::string textAfterV = line.substr(startPos, endPos - startPos);
            
            
            iText(395, yCoordinate, const_cast<char*>(textAfterV.c_str()), GLUT_BITMAP_HELVETICA_18);
			    yCoordinate -= 25;

			}
			else{
			
			iText(395, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_18);
			yCoordinate -= 25;
			}

		}
		else if (yCoordinate == 521)
		{
			iText(365, 526, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);
			yCoordinate -= 25;
			
		}
	}

	inputFile.close();

}

void livescore_3(){
	char fimage[22];
	char simage[22];
	if (next_click == 0) {
        strcpy(fimage, "livescore/5_5.bmp");
		strcpy(simage, "livescore/6_6.bmp");
    } else if (next_click == 1) {
        strcpy(fimage, "livescore/11_11.bmp");
		strcpy(simage, "livescore/12_12.bmp");
    }
	if (iDoesFileExist(fimage))
	{
	iShowBMP(689,596,fimage);
	}
	else
	{
		iShowBMP(100, 76, "1_imagecopy.bmp");
	}
	if (iDoesFileExist(simage))
	{
	iShowBMP(689,546,simage);
	}
	else
	{
		iShowBMP(100, 76, "1_imagecopy.bmp");
	}
	char txtname[30];
	  if (next_click == 0) {
        strcpy(txtname, "livescore/match_details_3.txt");
    } else if (next_click == 1) {
        strcpy(txtname, "livescore/match_details_6.txt");
    }

	
	std::ifstream inputFile(txtname);

	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file." << std::endl;
		return;
	}

	std::string line;
	int yCoordinate = 636;

	while (std::getline(inputFile, line))
	{
		iSetColor(0, 0, 0);
		if (yCoordinate == 636)
		{
			iText(702, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);

			yCoordinate -= 40;
		}
		else if (yCoordinate == 596)
		{
			iText(720, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_18);
			yCoordinate -= 50;
		}
		else if (yCoordinate == 546)
		{
			
		
			size_t vPosition = line.find("v");
			if (vPosition != std::string::npos)
			{
				 size_t startPos = vPosition + 2; 
            size_t endPos = std::min(startPos + 5, line.length());
            std::string textAfterV = line.substr(startPos, endPos - startPos);
            
            
            iText(720, yCoordinate, const_cast<char*>(textAfterV.c_str()), GLUT_BITMAP_HELVETICA_18);
			    yCoordinate -= 25;

			}
			else{
			
			iText(720, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_18);
			yCoordinate -= 25;
			}

		}
		
		else if (yCoordinate == 521)
		{
			iText(690, 526, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);
			yCoordinate -= 25;
			
		}
	}

	inputFile.close();
}

void detailscore(){
	iShowBMP(0,0,"introAnimation/Detail_Score.bmp");
}
void detailscore_1(){
	std::ifstream inputFile("morescore/first.txt");

	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file." << std::endl;
		return;
	}

	std::string line;
	int yCoordinate = 610;
	while (std::getline(inputFile, line))
	{
		iSetColor(0, 0, 0);
		if (yCoordinate == 610)
		{
			iText(52, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_18);
			yCoordinate -= 70;
		}
		else if (yCoordinate == 540)
		{
			iText(52, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);
			yCoordinate -= 20;
		}
		else
		{
			iText(52, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);
			yCoordinate -= 20;
		}
	}

	inputFile.close();
}
void detailscore_2(){
	std::ifstream inputFile("morescore/first_2.txt");

	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file." << std::endl;
		return;
	}

	std::string line;
	int yCoordinate = 610;
	while (std::getline(inputFile, line))
	{
		iSetColor(0, 0, 0);
		if (yCoordinate == 610)
		{
			iText(680, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_18);
			yCoordinate -= 70;
		}
		else if (yCoordinate == 540)
		{
			iText(680, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);
			yCoordinate -= 20;
		}
		else
		{
			iText(680, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);
			yCoordinate -= 20;
		}
	}

	inputFile.close();

}
void detailscore_3(){
	std::ifstream inputFile("morescore/second.txt");

	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file." << std::endl;
		return;
	}

	std::string line;
	int yCoordinate = 610;
	while (std::getline(inputFile, line))
	{
		iSetColor(0, 0, 0);
		if (yCoordinate == 610)
		{
			iText(52, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_18);
			yCoordinate -= 70;
		}
		else if (yCoordinate == 540)
		{
			iText(52, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);
			yCoordinate -= 20;
		}
		else
		{
			iText(52, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);
			yCoordinate -= 20;
		}
	}

	inputFile.close();
}
void detailscore_4(){
	std::ifstream inputFile("morescore/second_2.txt");

	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file." << std::endl;
		return;
	}

	std::string line;
	int yCoordinate = 610;
	while (std::getline(inputFile, line))
	{
		iSetColor(0, 0, 0);
		if (yCoordinate == 610)
		{
			iText(680, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_18);
			yCoordinate -= 70;
		}
		else if (yCoordinate == 540)
		{
			iText(680, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);
			yCoordinate -= 20;
		}
		else
		{
			iText(680, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);
			yCoordinate -= 20;
		}
	}

	inputFile.close();

}
void detailscore_5(){
	std::ifstream inputFile("morescore/third.txt");

	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file." << std::endl;
		return;
	}

	std::string line;
	int yCoordinate = 610;
	while (std::getline(inputFile, line))
	{
		iSetColor(0, 0, 0);
		if (yCoordinate == 610)
		{
			iText(52, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_18);
			yCoordinate -= 70;
		}
		else if (yCoordinate == 540)
		{
			iText(52, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);
			yCoordinate -= 20;
		}
		else
		{
			iText(52, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);
			yCoordinate -= 20;
		}
	}

	inputFile.close();
}
void detailscore_6(){
	std::ifstream inputFile("morescore/third_2.txt");

	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file." << std::endl;
		return;
	}

	std::string line;
	int yCoordinate = 610;
	while (std::getline(inputFile, line))
	{
		iSetColor(0, 0, 0);
		if (yCoordinate == 610)
		{
			iText(680, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_18);
			yCoordinate -= 70;
		}
		else if (yCoordinate == 540)
		{
			iText(680, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);
			yCoordinate -= 20;
		}
		else
		{
			iText(680, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);
			yCoordinate -= 20;
		}
	}

	inputFile.close();

}
void detailscore_7(){
	std::ifstream inputFile("morescore/forth.txt");

	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file." << std::endl;
		return;
	}

	std::string line;
	int yCoordinate = 610;
	while (std::getline(inputFile, line))
	{
		iSetColor(0, 0, 0);
		if (yCoordinate == 610)
		{
			iText(52, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_18);
			yCoordinate -= 70;
		}
		else if (yCoordinate == 540)
		{
			iText(52, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);
			yCoordinate -= 20;
		}
		else
		{
			iText(52, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);
			yCoordinate -= 20;
		}
	}

	inputFile.close();
}
void detailscore_8(){
	std::ifstream inputFile("morescore/forth_2.txt");

	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file." << std::endl;
		return;
	}

	std::string line;
	int yCoordinate = 610;
	while (std::getline(inputFile, line))
	{
		iSetColor(0, 0, 0);
		if (yCoordinate == 610)
		{
			iText(680, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_18);
			yCoordinate -= 70;
		}
		else if (yCoordinate == 540)
		{
			iText(680, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);
			yCoordinate -= 20;
		}
		else
		{
			iText(680, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);
			yCoordinate -= 20;
		}
	}

	inputFile.close();

}
void detailscore_9(){
	std::ifstream inputFile("morescore/fifth.txt");

	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file." << std::endl;
		return;
	}

	std::string line;
	int yCoordinate = 610;
	while (std::getline(inputFile, line))
	{
		iSetColor(0, 0, 0);
		if (yCoordinate == 610)
		{
			iText(52, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_18);
			yCoordinate -= 70;
		}
		else if (yCoordinate == 540)
		{
			iText(52, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);
			yCoordinate -= 20;
		}
		else
		{
			iText(52, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);
			yCoordinate -= 20;
		}
	}

	inputFile.close();
}
void detailscore_10(){
	std::ifstream inputFile("morescore/fifth_2.txt");

	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file." << std::endl;
		return;
	}

	std::string line;
	int yCoordinate = 610;
	while (std::getline(inputFile, line))
	{
		iSetColor(0, 0, 0);
		if (yCoordinate == 610)
		{
			iText(680, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_18);
			yCoordinate -= 70;
		}
		else if (yCoordinate == 540)
		{
			iText(680, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);
			yCoordinate -= 20;
		}
		else
		{
			iText(680, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);
			yCoordinate -= 20;
		}
	}

	inputFile.close();

}
void detailscore_11(){
	std::ifstream inputFile("morescore/sixth.txt");

	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file." << std::endl;
		return;
	}

	std::string line;
	int yCoordinate = 610;
	while (std::getline(inputFile, line))
	{
		iSetColor(0, 0, 0);
		if (yCoordinate == 610)
		{
			iText(52, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_18);
			yCoordinate -= 70;
		}
		else if (yCoordinate == 540)
		{
			iText(52, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);
			yCoordinate -= 20;
		}
		else
		{
			iText(52, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);
			yCoordinate -= 20;
		}
	}

	inputFile.close();
}
void detailscore_12(){
	std::ifstream inputFile("morescore/sixth_2.txt");

	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file." << std::endl;
		return;
	}

	std::string line;
	int yCoordinate = 610;
	while (std::getline(inputFile, line))
	{
		iSetColor(0, 0, 0);
		if (yCoordinate == 610)
		{
			iText(680, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_18);
			yCoordinate -= 70;
		}
		else if (yCoordinate == 540)
		{
			iText(680, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);
			yCoordinate -= 20;
		}
		else
		{
			iText(680, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_12);
			yCoordinate -= 20;
		}
	}

	inputFile.close();

}
void international_series(){
	std::ifstream inputFile("leagues/schedule_info.txt");

	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file." << std::endl;
		return;
	}

	std::string line;
	int yCoordinate = 488;
	while (std::getline(inputFile, line))
	{
		iSetColor(0, 0, 0);
		if (yCoordinate == 488)
		{
			iText(88, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_9_BY_15);
			
		}
		
		else
		{
			iText(88, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_9_BY_15);
			
		}
		yCoordinate-=53;
	}

	inputFile.close();



}
void local_match(){
	std::ifstream inputFile("leagues/domestic_schedule_info.txt");

	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file." << std::endl;
		return;
	}

	std::string line;
	int yCoordinate = 488;
	while (std::getline(inputFile, line))
	{
		iSetColor(0, 0, 0);
		if (yCoordinate == 488)
		{
			iText(750, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_9_BY_15);
			
		}
		
		else
		{
			iText(750, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_9_BY_15);
			
		}
		yCoordinate-=53;
	}

	inputFile.close();



}
int current_stat=0;
void homePage()
{
	if (screenClicked)
	{
		homescreen();
		homepagenews();
		livescore_1();
		livescore_2();
		livescore_3();
		home_mostread_news();
		current_stat=1;

	}
}
void home_slide_image_animation()
{
	if (slide_image == 6)
	{
		homePage();
	}
	else
	{
		Sleep(12);
		iShowBMP(0, 0, home_slide_images[slide_image]);
		homepagenews();
		home_mostread_news();

		slide_image++;
	}
}
void login_page(){
	iShowBMP(0,0,"introAnimation/login_image.bmp");
	if (mode==2)
	{
		iSetColor(0,0,0);
		iText(468,382,user,GLUT_BITMAP_HELVETICA_18);
		iText(468,265,password,GLUT_BITMAP_HELVETICA_18);
	}
	
		
}
void signup_page(){
	iShowBMP(0,0,"introAnimation/Signup_image.bmp");
	if(mode==1){
		iSetColor(0,0,0);
		iText(468,382,usersignup,GLUT_BITMAP_HELVETICA_18);
		iText(468,265,passsignup,GLUT_BITMAP_HELVETICA_18);
		
	}


}
void adduser(const char* new_username, const char* new_password){
		char *filename ="Credientals.txt";
		 if (new_username == NULL || new_password == NULL || new_password[0] == '\0' || new_username[0] == '\0') {
        printf("Error: Empty string detected. Not writing to the file.\n");
        return;
    }
	else{

			FILE *fp =fopen(filename,"a");
			if (fp==NULL)
			{
				printf("Error");
				
			}
			
				fprintf(fp,"%s,%s\n",new_username,new_password);
			
		fclose(fp);

}
}
int login_image=0;

int checkCredentials(const char *username, const char *password) {
    char *filename ="Credientals.txt";
	
	FILE *file = fopen(filename, "r");
    if (!file) return 0;

    char line[MAX_LENGTH];
    

    while (fgets(line, MAX_LENGTH, file) != NULL) {
        line[strcspn(line, "\n")] = 0;
        char fileUsername[MAX_LENGTH], filePassword[MAX_LENGTH];
        if (sscanf(line, "%[^,],%s", fileUsername, filePassword) == 2 &&
            strcmp(username, fileUsername) == 0 && strcmp(password, filePassword) == 0) {
            login = 1;
            break;
        }
		else{
			wrong=1;
		}
    }

    fclose(file);
    return login;
}
void savelogin(const char *username, const char *password){
	char *filename ="tries.txt";
	FILE *fp =fopen(filename,"w");
			if (fp==NULL)
			{
				printf("Error");
				
			}
			
				fprintf(fp,"%s\n%s\n",username,password);
			
		fclose(fp);
	FILE *file = fopen(filename, "r");
}
int user_text_len=0;
void free_user_text_input(char *user_text_free){
	// while(user_text_len>=0){
	// 	user_text_free[user_text_len]='\0';
	// 	user_text_len--;
	// }
	int len = strlen(user_text_free);
	while(len>=0){
		user_text_free[len]='\0';
		len--;
	}
	// memset(user_text_free, '\0', sizeof(user_text_free));
	user_text_len=0;
}
void login_sucess(){
		iShowBMP(0,0,"introAnimation/login_sucess.bmp");
		std::ifstream inputFile("tries.txt");

	if (!inputFile.is_open())
	{
		std::cerr << "Error opening file." << std::endl;
		return;
	}

	std::string line;
	int yCoordinate = 440;
	while (std::getline(inputFile, line))
	{
		iSetColor(0, 0, 0);
		if (yCoordinate == 440)
		{
			iText(551, yCoordinate, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_18);
			
		}
		
		else
		{
			iText(551, 375, const_cast<char *>(line.c_str()), GLUT_BITMAP_HELVETICA_18);
			
		}
		yCoordinate-=53;
	}

	inputFile.close();
		
		

}
void wrongformat(){
	if (wrong==1)
	{
		iSetColor(136,8,8);
	iText(511,480,"Wrong Format or Password",GLUT_BITMAP_HELVETICA_18);
	}

}
void wrongformat_1(){
	if (wrong==2)
	{
		iSetColor(136,8,8);
	iText(511,480,"Wrong Format or Password",GLUT_BITMAP_HELVETICA_18);
	}

}
void iDraw()
{
	if (introimage != 132)
	{
		introanimation();
	}

	homePage();

	switch (i)
	{
	case 1:
		homePage();

		break;
	case 2:
		newspage();
		surfacenews();
		surfacenews_images();
		mostread_news();
		current_stat=2;
		newscheck==1;
		break;
	case 3:
		leagues();
		international_series();
		local_match();
		current_stat=3;
		break;
	case 4:
		statsPage();
		statspage_oditeam_data();
		statspage_testteam_data();
		t20team();
		current_stat=4;
		break;
	case 5:
		detailnews_2();
		current_stat=5;
		break;
	case 6:
		home_slide_image_animation();
		current_stat=1;

		break;
	case 7:
		detailscore();
		if (next_click==0 && match==1)
		{
			detailscore_1();
			detailscore_2();
			
		

		}
		else if (next_click==0 && match==2)
		{
			detailscore_3();
			detailscore_4();
		}
		else if (next_click==0 && match==3)
		{
			detailscore_5();
			detailscore_6();
		}
		else if (next_click==1 && match==1)
		{
			detailscore_7();
			detailscore_8();
		}
		else if (next_click==1 && match==2)
		{
			detailscore_9();
			detailscore_10();
		}
		else if (next_click==1 && match==3)
		{
			detailscore_11();
			detailscore_12();
		}
		
		
		
		
		current_stat=7;
		break;
	case 8:
		if (login_image==1)
	{
		login_sucess();
	}
	else{
		login_page();
		wrongformat();
		current_stat=8;

	}
		
		
		break;
	case 9:
		signup_page();
		wrongformat();

		current_stat=9;
		break;
	case 10:
		batsman_ranking();
		t20_bat();
		test_bat();
		odi_bat();
		current_stat=10;
		break;
	case 11:
		bowler_ranking();
		current_stat=11;
		t20_bowl();
		odi_bowl();
		test_bowl();
		break;
	default:
		break;
	}
	
	
	// if (homepageclick)
	// {
	// 	homescreen();
	// }

	// if (nextpageClick)
	// {
	// 	newspage();
	// }

	// if(rankClick){
	// 	ranking();

	// }
	// "if (homepageclick){
	// 	mainscreen();
	// }"
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my)
{
	printf("x = %d, y= %d\n", mx, my);
	// place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		// Change screen state on mouse click
		screenClicked = true;
		

		// if (mx <= 820 && mx >= 750 && my <= 790 && mx >= 760)
		// {
		// 	homepageclick=true;
		// }
		if (mx <= 920 && mx >= 890 && my <= 710 && my >= 690)
		{

			i = 2;
		}
		if (mx <= 815 && mx >= 770 && my <= 705 && my >= 690)
		{

			i = 1;
			printf("om");
		}

		if (mx <= 1040 && mx >= 975 && my <= 700 && my >= 680)
		{
			i = 3;
		}

		if (mx <= 1140 && mx >= 1100 && my <= 700 && my >= 680)
		{
			i = 4;
		}
		if (mx <= 976 && mx >= 334 && my <= 537 && my >= 423)
		{
			if (newscheck == 1)
			{
				i = 5;
			}
		}
		if (mx <= 56 && mx >= 27 && my <= 598 && my >= 590)
		{
			i = 2;
		}
		if (mx <= 941 && mx >= 326 && my <= 376 && my >= 282)
		{
			if (newscheck == 1)
			{
				i = 5;
			}
		}
		if (mx <= 1100 && mx >= 950 && my <= 587 && my >= 557)
		{
			if (current_stat==1)
			{
				i = 6;
			slide_image = 0;

			if (next_click==0)
			{
				next_click=1;
			}
			else{
				next_click=0;
			}
			printf("%d",next_click);
			}
			}
			
		if (mx <= 286 && mx >= 49 && my <= 640 && my >= 500){
			if (current_stat==1)
			{
				i=7;
				match=1;
			}
			
		}
		if (mx<=306 && mx>=270 && my<=662 && my>=636){
			if (current_stat==4)
			{
				i=10;
			}
			
		}
		if (mx<=366 && mx>=338 && my<=663 && my>=636){
			if (current_stat==10)
			{
				i=11;
			}
			
		}
		if (mx<=367 && mx>=334 && my<=658 && my>=634){
			if (current_stat==11)
			{
				i=4;
			}
			
		}
		if (mx <= 605 && mx >= 365 && my <= 640 && my >= 500){
			if (current_stat==1)
			{
				i=7;
				match=2;
			}
		}
		if (mx <= 930 && mx >= 680 && my <= 640 && my >= 500){
			if (current_stat==1)
			{
				i=7;
				match=3;
			}
		}
		if (mx <= 1270 && mx >= 1230 && my <= 710 && my >= 680){
				
				
				
					i=8;
				
		}
		if (mx<=835 && mx>=745 && my<=560 && my>=526)
		{	if (current_stat==8)
		{
			i=9;
		}
		}
		if (mx<=540 && mx>=455 && my<=560 && my>=530)
		{	if (current_stat==9)
		{
			i=8;
		}
		}
		if (mx<=840 && mx>=460 && my<=425 && my>=367)
		{	if (current_stat==9)
		{
			
			mode=1;
			signuser=1;
			printf("om");
		}}
		if (mx<=840 && mx>=460 && my<=312 && my>=242)
		{	if (current_stat==9)
		{
		
			mode=1;
			signuser=2;
			printf("om");
		}
		}
		if (mx<=790 && mx>=525 && my<=205 && my>=160)
		{	if (current_stat==9)
		{
			
			adduser(usersignup,passsignup);
			
			if (usersignup == NULL || passsignup == NULL || usersignup[0] == '\0' || passsignup[0] == '\0'){
				wrong=1;
			}
			else{
			i=8;
			free_user_text_input(usersignup);
			free_user_text_input(passsignup);
			wrong=0;
			}
			mx=0;
			my=0;
			
		}
		}
		//loginpage
		if (mx<=840 && mx>=460 && my<=425 && my>=367)
		{	if (current_stat==8)
		{
			
			mode=2;
			signuser=1;
			printf("om");
		}
		}
		if (mx<=840 && mx>=460 && my<=312 && my>=242)
		{	if (current_stat==8)
		{
		
			mode=2;
			signuser=2;
			printf("om");
			printf("%d",signuser);
		}
		}
		
		if (mx<=790 && mx>=525 && my<=205 && my>=160)
		{	if (current_stat==8)
		{
			
			
			if (user == NULL || password == NULL || user[0] == '\0' || password[0] == '\0'){
				wrong=1;
			}
			else{
				
			savelogin(user,password);
			login=checkCredentials(user,password);
			wrong=0;

			
			
			}
			if(login==1){
				i=1;
			login_image=1;
			free_user_text_input(user);
			free_user_text_input(password);
			}

			mx=0;
			my=0;
			
		}
		}
		if (mx<=488 && mx>=408 && my<=166 && my>=104 && login==1){
			login_image=0;
			i=8;
		}
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key)
{
	int i;
	if(mode==1&&signuser==1){
		if(key == '\b')
			{
				if(signuser_len > 0)
				{
					signuser_len--;
					usersignup[signuser_len] = 0;
				}
			}
			else
			{
				usersignup[signuser_len] = key;
				signuser_len++;
			}

	}
	if(mode==1&&signuser==2){
		if(key == '\b')
			{
				if(signpass_len > 0)
				{
					signpass_len--;
					passsignup[signpass_len] = 0;
				}
			}
			else
			{
				passsignup[signpass_len] = key;
				signpass_len++;
			}

	}
	if(mode==2&&signuser==1){
		if(key == '\b')
			{
				if(user_len > 0)
				{
					user_len--;
					user[user_len] = 0;
				}
			}
			else
			{
				user[user_len] = key;
				user_len++;
			}
					printf("%d",signuser);
					

	}
	if(mode==2&&signuser==2){
		if(key == '\b')
			{
				if(pass_len > 0)
				{
					pass_len--;
					password[pass_len] = 0;
				}
			}
			else
			{
				password[pass_len] = key;
				pass_len++;
			}}
			
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
	}
	// place your codes for other keys here
}

int main()
{
	// place your own initialization codes here.
	iInitialize(screenWidth, screenHeight, "CricInfo");
	iDraw();
	return 0;
}