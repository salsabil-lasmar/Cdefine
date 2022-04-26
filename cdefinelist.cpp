#include "cdefinelist.h"
#include"cdefine.h"
#include<QVector>
#include<QFile>
#include<QRegularExpression>
#include<QRegularExpressionMatch>
#include<QTextStream>
#include<QDebug>
CDefineList::CDefineList(){

                          }


void CDefineList ::init()
{
    mDefineList.clear();
    QString path = "C:\\Users\\salsabil.lasmar\\Desktop\\define\\DEFINE.H";//CoDefine.h
    setDefineList(path); // map complete
   // managePendingPreprocessor() ;
}
/**
 * @brief setDefineList
 * @param path
 */
void CDefineList :: setDefineList(QString path){


    QFile file(path);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream flux(&file);

        QRegularExpression rexpUnDefine("^(?!.*(^//)).*#undef\\s([A-Z0-9_]*)(\\s+.*)*");
        QRegularExpression rexpDefine("^(?!.*(^//)).*#define\\s*([a-zA-Z0-9_]*)(\\s+.*)*");
        QRegularExpression endConditionDefine("^(?!.*(^//)).*#endif)");
        QRegularExpression rexpMacroCondition("^(?!.*(^//)).*#(ifdef\\s([A-Z0-9_]*)|if\\sdefined\\(\\s([A-Z0-9_]*)\\))");
        QRegularExpression rexpValue("[^//]*");
        QRegularExpression rexpInclude("^(?!.*(^//)).*#include\\s*<(.+)>.*");


        while (!flux.atEnd()) {

            QString line = flux.readLine();

            // fonction mangeIncludeDefines{
            QRegularExpressionMatch includeMatcher = rexpInclude.match(line);
            if(includeMatcher.hasMatch()) {
                QString sFileName = includeMatcher.captured(2).replace("//s","");
                QString sincludedPath =path.replace("DEFINE.H",sFileName);

                setDefineList(sincludedPath);

                continue;
             }





           // fonction manage conditionnalDefines
            // get preprocessor name and value from line which starts with #ifdef __salsabil__
            QRegularExpressionMatch MacroConditionMatcher = rexpMacroCondition.match(line);
            if(MacroConditionMatcher.hasMatch()) {
                QString sName = MacroConditionMatcher.captured(2).replace("//s", "");
                if(!mDefineList.contains(sName))
                    parents.push_back(sName);

               continue;

              }

            // fonction manageEndCondtionnalDefines
            // get preprocessor name and value from line which starts with #endif_
            QRegularExpressionMatch endConditionDefineMatcher = endConditionDefine.match(line);
            if(endConditionDefineMatcher.hasMatch()) {
                if(parents.size() == 0) continue;
                parents.pop_back();

              }

            //remove from the map the  undefine name
            QRegularExpressionMatch rexpUnDefineMatcher = rexpUnDefine.match(line);
             if (rexpUnDefineMatcher.hasMatch()){
                QString sNameundef = rexpUnDefineMatcher.captured(2).replace("//s", "");
                undefinePreprocessor(sNameundef);
             }


            //setNewDefine

            // get preprocessor name and value from line which starts with #define
            QRegularExpressionMatch rexpMatcher = rexpDefine.match(line);
            if(rexpMatcher.hasMatch()) {
                CDefine *oDefine = new CDefine();
                oDefine->type_file=path;

                QString sName = rexpMatcher.captured(2).replace("//s", "");
                 oDefine->name = sName;

                QString sValueGroup = rexpMatcher.captured(3).replace("//s", "");



                QRegularExpressionMatch rexpMatcherValueGroup = rexpValue.match(sValueGroup);
                if(rexpMatcherValueGroup.hasMatch()) {
                    QString sValue = rexpMatcherValueGroup.captured(0).replace("//s", "");
                    oDefine->value = sValue;
                   }
                if(parents.size() != 0)
                {
                    oDefine->parent=parents;
                    oDefine->eState=pending;
                    pendingDefines++;
                }else
                {
                     oDefine->eState=activated;
                }


                mDefineList.insert(sName,*oDefine);

                     }

              }

        }

    file.close();
    }



void CDefineList :: undefinePreprocessor(QString sNameundef){
    for ( const CDefine &mdefine:qAsConst(mDefineList) ){

        if (parents.contains(sNameundef)){
            parents.erase(&sNameundef);
        }
        if(mdefine.eState == pending){
            pendingDefines--;
        }
        mDefineList.remove(sNameundef);
    }
}

/*void CDefineList :: managePendingPreprocessor(){

   for(auto mDefine : mDefineList)


          while(pendingDefines != 0)
         {
                if(mDefine.eState != pending)
                    break;
                if(mDefine.parent.size()==0)
                    break;
                bool activatedDefine = true;

                // dans le cas ou parents size != 0 et state == pending

                for(auto &&parent : mDefine.parent)

                   // if(mDefineList.contains(parent))

                            if(mDefineList[parent].eState == activated)
                             {

                               activatedDefine = true;
                               pendingDefines--;

                               }
                            else if(mDefineList[parent].eState == pending)
                            {
                                 activatedDefine=false;
                                   break;
                              }


                else
                     {
                      mDefineList.remove(mDefine.name);
                        break;
                     }

               if((activatedDefine = true))
                {
                  mDefine.eState=activated;
                }

         }

      }

*/

