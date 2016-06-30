##############################################################################
#                                                                              
# Viktor Litvak
#
#                                                                              
###############################################################################
QT      +=  core gui webkit webkitwidgets network script widgets
HEADERS =   config.h \
		MainWindowContainer.h \
	    FBApi.h \	    
	    HttpClient.h \
	    UT.h  \
	    lib_json/json_batchallocator.h  \
	    lib_json/json_internalarray.inl \
	    lib_json/json_internalmap.inl \
	    lib_json/json_valueiterator.inl \
            likewindow.h
	    
	    
SOURCES =   main.cpp \
            MainWindowContainer.cpp \
	    FBApi.cpp \	    
	    HttpClient.cpp \
	    UT.cpp \
	    lib_json/json_reader.cpp \
	    lib_json/json_value.cpp \
	    lib_json/json_writer.cpp \
            likewindow.cpp

INCLUDEPATH += . lib_json/include lib_json/include/json

FORMS += fbapi_gui.ui \  
         likewindow.ui
	     
  

 
 
