#ifndef __HTTPCLIENT_H_
#define __HTTPCLIENT_H_
#include <QtWidgets>
#include <QtNetwork>
 
class HttpClient: public QObject

{
   Q_OBJECT
    
private: 
  static HttpClient* _instance;
  HttpClient();
  
  HttpClient(const HttpClient &);
  HttpClient & operator=(const HttpClient &);
  bool HandlePostRequestARGS(QByteArray& postArgs,
							const QMap<QString,QString>& paramsToPostMap,
							QString& ArgsAsString);
  

 
  
  int httpGetId;
  bool httpRequestAborted;
  QNetworkAccessManager* networkManager;
  
  
protected slots:
	 

	 
public:
  static HttpClient* getInstance();
  ~HttpClient(){}
  bool GetRequest(QString& ApiResponse,QMap<QString,QString> paramsToPostMap,QString& BaseUrl);
  bool PostRequest( QString& ApiResponse,QMap<QString,QString> paramsToPostMap,QString& BaseUrl );
  bool finishedNetWorkSlot(QNetworkReply* reply,
	  QNetworkReply::NetworkError& networkError);
  QNetworkAccessManager* getQNAManager();
  void HandleNetworkError(QNetworkReply::NetworkError& networkError);
  static bool IsUserAutorized;
   
};

#endif
