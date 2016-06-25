#include <iostream>
#include <stdio.h>
#include <curl/curl.h>

int main(void)
{
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  if(curl) {
    
	//curl_easy_setopt(curl, CURLOPT_URL, "https://api.instagram.com/v1/users/3124248220/media/recent/?access_token=3124248220.1677ed0.d02014c9e9a14235bbb83d1bca2717e7");
    //curl_easy_setopt(curl, CURLOPT_URL, "https://graph.facebook.com/100008129298080/picture");
	curl_easy_setopt(curl, CURLOPT_URL, "https://graph.facebook.com/1707734546174172/likes?access_token=CAACEdEose0cBAPIGMkOJjnDD0VQ2XN4FzI51ZAUbvQjsYQCnLiVZA6QWHLBzhLtZCnnTwUlgon92Ulfnan0PDZAyOfJdUnwLFDBFPntaqvJ3c6SUFgIEfbA6KwKJV4nPQzE7dq7M5G0wsUsjUvO2BQdP14OC640dV7EpWhjDFQEiEIKvuvCZCY3XPHWycYYWtme57JhmkjgZDZD");

	/* example.com is redirected, so we tell libcurl to follow redirection */

    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    /* Perform the request, res will get the return code */
    res = curl_easy_perform(curl);

    //std::cout << "\n \n \nLenth = "<<sizeof(res);


    /* Check for errors */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));

    /* always cleanup */
    curl_easy_cleanup(curl);
  }
  return 0;
}
