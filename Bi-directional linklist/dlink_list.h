
#ifndef _DLINK_LIST_H_
#define _DLINK_LIST_H_

typedef void DLinkList;

//˫������  С���
typedef struct _tag_DLinkListNode
{
	struct _tag_DLinkListNode *next;
	struct _tag_DLinkListNode *pre;
}DLinkListNode;

//��������
DLinkList* DLinkList_Create();

//��������
void DLinkList_Destroy(DLinkList *list);

//�������
void DLinkList_Clear(DLinkList *list);

//��ȡ������
int DLinkList_Length(DLinkList *list);


//����Ԫ�� ��pos λ��
int DLinkList_Insert(DLinkList *list, DLinkListNode *node, int pos);


//��ȡ�� pos��λ��Ԫ��
DLinkListNode* DLinkList_GetByPos(DLinkList *list, int pos);


//ɾ�� posλ��Ԫ��
DLinkListNode* DLinkList_Delete(DLinkList *list, int pos);


//add

//ָ��ɾ�������� ĳ������Ԫ��
DLinkListNode* DLinkList_DeleteNode(DLinkList *list, DLinkListNode *node);

//�����α� λ��,�������ú� ��ָԪ��
DLinkListNode* DLinkList_Reset(DLinkList *list);

//��ȡ��ǰ �α�ָ�� ����Ԫ��
DLinkListNode* DLinkList_Current(DLinkList *list);

//���α�ָ����һ�� ����Ԫ��
DLinkListNode* DLinkList_Next(DLinkList *list);

//���α�ָ����һ�� ����Ԫ��
DLinkListNode* DLinkList_Pre(DLinkList *list);

#endif