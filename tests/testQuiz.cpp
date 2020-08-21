//
// Created by Sabrina on 24/04/2020.
//

#include <time.h>
#include "testQuiz.h"
#include "../quiz.h"
#include "../questions.h"

void testQuiz(){
    srand(time(NULL));
    QuestionnaireData* questionnaireList = nullptr;
    QuestionsData* listBiology = nullptr;
    QuestionsData* listChemistry = nullptr;
    QuestionsData* listPortuguese = nullptr;
    createQuiz("Biology Quiz", "biology", questionnaireList);
    showQuizList(questionnaireList);
    createQuiz("Portuguese Quiz", "portuguese", questionnaireList);
    showQuizList(questionnaireList);
    createQuiz("Chemistry Quiz", "chemistry", questionnaireList);
    showQuizList(questionnaireList);

    std::string questionHeader1 = "Atualmente existem quantos elementos quimicos na 'Tabela Periodica'?";
    std::string answerA1 = "A - 90 elementos";
    std::string answerA2 = "B - 142 elementos";
    std::string answerA3 = "C - 110 elementos";
    std::string answerA4 = "D - 113 elementos";
    int rightAnswerA = 4;
    int id = 1;
    std::string discipline1 = "chemistry";

    Questions questions1 = createQuestion(questionHeader1,answerA1,answerA2,answerA3,answerA4,rightAnswerA, listChemistry);
    insertAtDisciplineEnd(listChemistry, questions1, questionnaireList, discipline1);

    std::string questionHeader2 = "Qual elemento quimico que se encontra na Familia VII A e no 5 periodo?";
    std::string answerB1 = "A - Fluor";
    std::string answerB2 = "B - Oxigenio";
    std::string answerB3 = "C - Iodo";
    std::string answerB4 = "D - Bromo";
    int rightAnswerB = 3;

    Questions questions2 = createQuestion(questionHeader2,answerB1,answerB2,answerB3,answerB4,rightAnswerB, listChemistry);
    insertAtDisciplineEnd(listChemistry, questions2, questionnaireList, discipline1);
    showQuestionList(listChemistry);


    std::string questionHeader3 = "Assinale a alternativa que nao representa uma doenca causada por virus";
    std::string answerC1 = "A - variola";
    std::string answerC2 = "B - raiva";
    std::string answerC3 = "C - poliomelite";
    std::string answerC4 = "D - tetano";
    int rightAnswerC = 4;
    std::string discipline2 = "biology";

    Questions questions3 = createQuestion(questionHeader3,answerC1,answerC2,answerC3,answerC4,rightAnswerC, listBiology);
    insertAtDisciplineEnd(listBiology, questions3, questionnaireList, discipline2);

    std::string questionHeader4 = "A celula procariotica e desprovida de um?";
    std::string answerD1 = "A - Ribossomos";
    std::string answerD2 = "B - Nucleo";
    std::string answerD3 = "C - Citoplasma";
    std::string answerD4 = "D - Plasmideo";
    int rightAnswerD = 2;

    Questions questions4 = createQuestion(questionHeader4,answerD1,answerD2,answerD3,answerD4,rightAnswerD, listBiology);
    insertAtDisciplineEnd(listBiology, questions4, questionnaireList, discipline2);
    showQuestionList(listBiology);

    std::string questionHeader5 = "O complexo Golgiense e responsavel pela:";
    std::string answerE1 = "A - Obtencao de energia";
    std::string answerE2 = "B - Digestao intracelular";
    std::string answerE3 = "C - Respiracao celular";
    std::string answerE4 = "D - Divisao celular";
    int rightAnswerE = 2;
    int ide = questions3->id;

    updateQuestion(questionHeader5,answerE1,answerE2, answerE3, answerE4, rightAnswerE, ide, listBiology);
    showQuestionList(listBiology);

    std::string newTitle = "Matematica Quizz";
    std::string newDiscipline = "matematica";
    std::string discipline03 = "portuguese";

    updateQuiz(newTitle, discipline03, newDiscipline, questionnaireList);
    showQuizList(questionnaireList);

    Questions element = find(listBiology, ide);
    std::cout << element->questionHeader << std::endl;
    //removeAll(questionnaireList,listBiology,discipline2);
    //removeQuestionsList(listBiology);
    //showQuestionList(listBiology);
    //showQuizList(questionnaireList);
}