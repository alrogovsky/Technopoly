//
//  Data.cpp
//  Technopoly
//
//  Created by Олег Ермаков on 30.05.15.
//
//


/*
 
В одних и тех же группах:
1) 1,3
2) 6,8,9
3) 11,13,14
4) 16,18,19
5) 21,23,24
6) 26,27,29
7) 31,32,34
8) 37,39
*/

#include "MainTableScene.h"
#define NumberOfSubjectCards 22
#define NumberOfOSCards 4
#define NumberOfComChest 3
#define NumberOfTaxPay 2
#define NumberOfChance 3
#define NumberOfTraining 2
#define NumberOfCorners 4

Card** MainTable::dataCards = new  Card* [MainTable::numbers_of_cards];
Group* MainTable::Groups = new  Group [MainTable::numbers_of_groups];
void InitData()
{
    //хранение индексов
    int indexSubject[NumberOfSubjectCards] =                    //все карты предметов
    {1,3,6,8,9,11,13,14,16,18,19,21,23,24,26,27,29,31,32,34,37,39};
    int indexOS[NumberOfOSCards] = {5,15,25,35};
    int indexChest[NumberOfComChest] = {2,17,33};
    int indexTax[NumberOfTaxPay] = {4,38};
    int indexChance[NumberOfChance] = {7,22,36};
    int indexTraining[NumberOfTraining] = {12,28};
    int indexCorner[NumberOfCorners] = {10,20,30,0};
    
    //инициализация каждой группы карт
    for(int i=0; i<NumberOfSubjectCards; i++)
    {
        MainTable::dataCards[indexSubject[i]] = new SubjectCard();
       // MainTable::dataCards[indexSubject[i]]->setName("Название конкретной карты");
       // MainTable::dataCards[indexSubject[i]]->setDescription("Какое-то описание карты");
        MainTable::dataCards[indexSubject[i]]->setIndex(indexSubject[i]);
        ((SubjectCard*)MainTable::dataCards[indexSubject[i]])->setPrice(100);
    }
    for(int i=0; i<NumberOfOSCards; i++)
    {
        MainTable::dataCards[indexOS[i]] = new ActionCard();
        MainTable::dataCards[indexOS[i]]->setName("Название");
        MainTable::dataCards[indexOS[i]]->setDescription("Описание");
        MainTable::dataCards[indexOS[i]]->setIndex(indexOS[i]);
    }
    for(int i=0; i<NumberOfComChest; i++)
    {
        MainTable::dataCards[indexChest[i]] = new ActionCard();
        MainTable::dataCards[indexChest[i]]->setName("Технопарк");
        MainTable::dataCards[indexChest[i]]->setDescription("Остановка на таком поле означает, что Вам выпадает карточка, которая может потребовать, чтобы Вы: \n*передвинули Вашу фишку\n*отправились в Больницу\n*выписались из Больницы\n*потратили время\n*получили время");
        MainTable::dataCards[indexChest[i]]->setIndex(indexChest[i]);
    }
    for(int i=0; i<NumberOfTaxPay; i++)
    {
        MainTable::dataCards[indexTax[i]] = new ActionCard();
        MainTable::dataCards[indexTax[i]]->setName("Неприятности случаются");
        MainTable::dataCards[indexTax[i]]->setDescription("Если Вы остановитесь на таком поле, Вам нужно просто потратить определенное количество времени.");
        MainTable::dataCards[indexTax[i]]->setIndex(indexTax[i]);
    }
    for(int i=0; i<NumberOfChance; i++)
    {
        MainTable::dataCards[indexChance[i]] = new ActionCard();
        MainTable::dataCards[indexChance[i]]->setName("Шанс");
        MainTable::dataCards[indexChance[i]]->setDescription("Остановка на таком поле означает, что Вам выпадает карточка, которая может потребовать, чтобы Вы: \n*передвинули Вашу фишку\n*отправились в Больницу\n*выписались из Больницы\n*потратили время\n*получили время");
        MainTable::dataCards[indexChance[i]]->setIndex(indexChance[i]);
    }
    for(int i=0; i<NumberOfTraining; i++)
    {
        MainTable::dataCards[indexTraining[i]] = new ActionCard();
        MainTable::dataCards[indexTraining[i]]->setName("Цель курса");
       // MainTable::dataCards[indexTraining[i]]->setDescription("Описание");
        MainTable::dataCards[indexTraining[i]]->setIndex(indexTraining[i]);
    }
    for(int i=0; i<NumberOfCorners; i++)
    {
        MainTable::dataCards[indexCorner[i]] = new ActionCard();
        MainTable::dataCards[indexCorner[i]]->setName("Название");
        MainTable::dataCards[indexCorner[i]]->setDescription("Описание");
        MainTable::dataCards[indexCorner[i]]->setIndex(indexCorner[i]);
    }
  
    MainTable::dataCards[indexTraining[0]]->setDescription("Повышение коммуникативной компетентности участников и развитие навыков эффективного делового общения для результативного и успешного взаимодействия с партнёрами с помощью использования технологий коммуникации.");
    MainTable::dataCards[indexTraining[1]]->setDescription("Изучение структуры и инструментов человекоориентированного подхода к разработке интерфейсов, основных принципов и паттернов разработки пользовательских интерфейсов, формирование навыков анализа, подбора и применения необходимого инструментария для решения поставленных интерфейсных задач.");

    //MainTable::dataCards[0] = new ActionCard();
    MainTable::dataCards[0]->setName("Круг Пройден!");
    MainTable::dataCards[0]->setDescription("При прохождении данного поля, вы получаете 200");
    
    MainTable::dataCards[10]->setName("Больница");
    MainTable::dataCards[10]->setDescription("Если Вы не были “отправлены в Больницу”, а просто остановились на поле в ходе игры, Вы не платите штрафа, так как Вы “Просто посетили” ее. Следующим ходом Вы можете двигаться дальше, как обычно.");
    
    MainTable::dataCards[20]->setName("Время попить кофе");
    MainTable::dataCards[20]->setDescription("Если Вы остановитесь на таком поле, просто отдохните до следующего Вашего хода. Вы находитесь здесь бесплатно и не подвергаетесь никаким штрафам.");
    
    MainTable::dataCards[30]->setName("Пора подлечиться!");
    MainTable::dataCards[30]->setDescription("Если Вы остановитесь на таком поле, вам придется отправиться в больницу.");
    
    MainTable::Groups[0].addCard(MainTable::dataCards[1]);
    MainTable::Groups[0].addCard(MainTable::dataCards[3]);
    MainTable::Groups[0].setName("Вступительные испытания");
    MainTable::Groups[0].setDescription("Цель собеседования – с одной стороны, проверить уровень знаний и навыков кандидатов, а с другой — сориентировать студентов, рассказать, чем занимаются в Технопарке, и выяснить, насколько это пересекается с их интересами и ожиданиями.");
    
    MainTable::Groups[1].addCard(MainTable::dataCards[6]);
    MainTable::Groups[1].addCard(MainTable::dataCards[8]);
    MainTable::Groups[1].addCard(MainTable::dataCards[9]);
    MainTable::Groups[1].setName("Цель курса");
    MainTable::Groups[1].setDescription("Формирование практических навыков и умений, необходимых специалистам по разработке программного обеспечения (ПО) UNIX-подобных операционных систем для участия в проектах промышленной разработки среднего уровня сложности на языках C и C++, в том числе для замещения стажерских должностей разработчиков серверной части высоконагруженных приложений");
    
    MainTable::Groups[2].addCard(MainTable::dataCards[11]);
    MainTable::Groups[2].addCard(MainTable::dataCards[13]);
    MainTable::Groups[2].addCard(MainTable::dataCards[14]);
    MainTable::Groups[2].setName("Цель курса");
    MainTable::Groups[2].setDescription("Всестороннее изучение устройства и принципа работы современных web приложений и сети WWW в целом, а также получение практических навыков web разработки. Акцент в курсе сделан на разработку серверного ПО, т.е. backend разработку.");
    
    MainTable::Groups[3].addCard(MainTable::dataCards[16]);
    MainTable::Groups[3].addCard(MainTable::dataCards[18]);
    MainTable::Groups[3].addCard(MainTable::dataCards[19]);
    MainTable::Groups[3].setName("Цель курса");
    MainTable::Groups[3].setDescription("Обучить основам алгоритмического программирования, привить практические навыки решения задач с помощью базовых алгоритмов и структур данных, сформировать правильное представление о времени работы и эффективности различных алгоритмов и структур данных.");
    
    MainTable::Groups[4].addCard(MainTable::dataCards[21]);
    //MainTable::dataCards[21]->setDescription("Курс направлен на приобретение студентами навыков работы в среде linux на уровнях базового администрирования и оценки работоспособности системы.");
    MainTable::Groups[4].addCard(MainTable::dataCards[23]);
    MainTable::Groups[4].addCard(MainTable::dataCards[24]);
    MainTable::Groups[4].setName("Цель курса");
    MainTable::Groups[4].setDescription("Открытые курсы");
    
    MainTable::Groups[5].addCard(MainTable::dataCards[26]);
    MainTable::Groups[5].addCard(MainTable::dataCards[27]);
    MainTable::Groups[5].addCard(MainTable::dataCards[29]);
    MainTable::Groups[5].setName("Цель курса");
    MainTable::Groups[5].setDescription("Получение студентами практических навыков создания клиент-серверного приложения на примере разработки сервера простой многопользовательской on-line игры в малых группах (4-6 человек).");
    
    MainTable::Groups[6].addCard(MainTable::dataCards[31]);
    MainTable::Groups[6].addCard(MainTable::dataCards[32]);
    MainTable::Groups[6].addCard(MainTable::dataCards[34]);
    MainTable::Groups[6].setName("Цель курса");
    MainTable::Groups[6].setDescription("Дать студентам навыки клиентской разработки, навыки работы с базовыми технологиями CSS и JS, а также обучить базовым принципам разработки под мобильные устройства.");
    
    MainTable::Groups[7].addCard(MainTable::dataCards[37]);
    MainTable::Groups[7].addCard(MainTable::dataCards[39]);
    MainTable::Groups[7].setName("Цель курса");
    MainTable::Groups[7].setDescription("Получение студентами знаний в области проектирования реляционных БД, эффективной работы с БД, оптимизации запросов и схем данных, изучение особенностей использования БД в проектах с высокой нагрузкой и/или использующих большие массивы данных, noSQL и его использование для решения прикладных задач в WWW.");
}
