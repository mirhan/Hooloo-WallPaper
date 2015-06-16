#!/usr/bin/python
# -*- coding: UTF-8 -*-

msg_dic = { 2817 : 'TRACE_INFO_TYPE_LOG' ,
            2818 : 'TRACE_INFO_TYPE_EVENT_CREATE_SUCCESS',
            2819 : 'TRACE_INFO_TYPE_EVENT_CREATE_FAIL',
            2820 : 'TRACE_INFO_TYPE_EVENT_UPDATE_SUCCESS',
            2821 : 'TRACE_INFO_TYPE_EVENT_UPDATE_FAIL',
            2822 : 'TRACE_INFO_TYPE_EVENT_DELETE',
            2823 : 'TRACE_INFO_TYPE_DATA',
            2824 : 'TRACE_INFO_TYPE_SIGNALLING',
            2825 : 'TRACE_INFO_TYPE_IMSI_REQ',
            2826 : 'TRACE_INFO_TYPE_CLOSE_FILE_REQ',
            2827 : 'TRACE_INFO_TYPE_ID_REQ_OBSOLETE',
            2828 : 'TRACE_INFO_TYPE_VERSION_MISMATCH',
            2829 : 'TRACE_INFO_TYPE_EVENT_SUBSCRIBER_DUMP',
            2830 : 'TRACE_INFO_TYPE_DB_DUMP_REQ',
            2831 : 'TRACE_INFO_TYPE_DB_DUMP_RESP',
            2832 : 'TRACE_INFO_GTP_TRACE_ACTIVATE_IND',
            2833 : 'TRACE_INFO_GTP_TRACE_DEACTIVATE_IND',
            2834 : 'TRACE_INFO_FILE_QUOTA_IND',
            2835 : 'TRACE_INFO_DISK_QUOTA_IND',
          }

msg = 'Jun  5 08:32:08.684892 debug CLA-0 trace_ctrl[18862]: [0]: LIBMSG: MMON;2635;1/1;IPC_IN;0800_FFFF_0400_49AE<2D00_000C_FFFF_C612;289020M;0; 03 00 00 00 0f 27 00 00 0f 27 00 00 0f 27 00 00 0f 27 00 00 11 0b 2d 00 00 0c ff ff 08 00 ff ff 04 00 00 12 c6 28 00 00 00 00 81 42 00 08 00 00 00 00 f1 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 41 53 31 30 2d 30 00 46 46 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 0b 0b (libmsg_msgmon.c:306) //29198'


def get_msg_type(msg_str):
    tmp = msg_str.split(';')
    msg_type_hex = tmp[-1][64:66] + tmp[-1][61:63]
    msg_type = int(msg_type_hex, 16)
    return msg_type

def main():
    print msg_dic[get_msg_type(msg)]

main()





