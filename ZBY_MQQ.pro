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
    DataInterPort \
    DataInterSerailPort \
    DataInterModbus \
    DataInterRabbitMQ \
    DataInterTcp \
    DataInterchange \
    LogController/LogController.pro \
    WeightModbus \
        ZBY_MQ/ZBY_MQ.pro

