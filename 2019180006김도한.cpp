#include "Judgment.h"
#include "2019180006.h"
#include "2019180031.h"
#include "2021180006.h"
#include "2021184025.h"
#include "2019180010.h"
#include "2021180033.h"
#include "2021182005.h"




int main(void)
{
	Judgment judgment;

	judgment.SetYourFunc(
		BlackAttack_2021182005,
		BlackDefence_2021182005, //내가 만든 소스코드 넣기
		WhiteAttack_2019180006,
		WhiteDefence_2019180006);
		judgment.GamePlay();

}