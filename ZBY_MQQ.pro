#TEMPLATE = subdirs

#SUBDIRS += \
#    DataInterModbus \
#    DataInterSerailPort \
#    LogController \
##    DataInterRabbitMQ \
##    DataInterchange \
##    Qamqp \
#    ZBY_MQ \

TEMPLATE = subdirs
    SUBDIRS += \
    DataInterSerailPort \
    DataInterModbus \
    DataInterRabbitMQ \
    DataInterchange \
        LogController/LogController.pro \
        ZBY_MQ/ZBY_MQ.pro

