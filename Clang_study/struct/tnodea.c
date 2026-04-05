#include <stdio.h>
#include <stdlib.h>

// 트리 노드 정의
typedef struct tnode
{
  int key;
  struct tnode *left;
  struct tnode *right;
} tnode;

/* =========================
   1. 노드 생성 함수
   ========================= */
tnode *createNode(int key)
{
  // 1) 메모리 할당 (malloc)
  // 2) key 값 저장
  // 3) left, right를 NULL로 초기화
  // 4) 생성된 노드 반환
  tnode *return_tnode = malloc(sizeof(tnode));
  if (return_tnode == NULL)
  {
    return NULL;
  }
  return_tnode->key = key;
  return_tnode->left = NULL;
  return_tnode->right = NULL;
  return return_tnode;
}

/* =========================
   2. insert (삽입)
   ========================= */
tnode *insert(tnode *root, int key)
{
  // 1) root가 NULL이면
  //    → 새 노드 생성해서 반환 (종료 조건)
  if (root == NULL)
  {
    return createNode(key);
  }
  // 2) key < root->key
  //    → 왼쪽 서브트리로 이동 (재귀 호출)
  //    → 결과를 root->left에 다시 연결
  else if (key < root->key)
  {
    root->left = insert(root->left, key);
    return root;
  }
  // 3) key > root->key
  //    → 오른쪽 서브트리로 이동 (재귀 호출)
  //    → 결과를 root->right에 다시 연결
  else if (key > root->key)
  {
    root->right = insert(root->right, key);
    return root;
  }
  // 4) key == root->key
  //    → 중복 처리 (무시 or 규칙 정의)
  else if (key == root->key)
  {
    return root;
  }

  // 5) root 반환
  return root;
}

/* =========================
   3. search (탐색)
   ========================= */
tnode *search(tnode *root, int key)
{
  // 1) root가 NULL이면 → 없음 (NULL 반환)
  if (root == NULL)
  {
    return NULL;
  }
  // 2) root->key == key → 찾음 (root 반환)
  else if ((*root).key == key)
  {
    return root;
  }
  // 3) key < root->key
  //    → 왼쪽으로 이동 (재귀)
  else if (key < root->key)
  {
    return search(root->left, key);
  }
  // 4) key > root->key
  //    → 오른쪽으로 이동 (재귀)
  else
  {
    return search(root->right, key);
  }
}

/* =========================
   4. inorder traversal (정렬 출력)
   ========================= */
void inorder(tnode *root)
{
  // 1) root가 NULL이면 종료
  if (root == NULL)
  {
    return;
  }
  // 2) 왼쪽 서브트리 방문
  inorder(root->left);
  // 3) 현재 노드 출력 (key)
  printf("%d ", root->key);
  // 4) 오른쪽 서브트리 방문
  inorder(root->right);
}

/* =========================
   main (테스트)
   ========================= */
int main()
{
  tnode *root = NULL;

  // 1) insert 여러 개 호출해서 트리 구성
  root = insert(root, 2);
  insert(root, 5);
  insert(root, 10);
  insert(root, 7);
  insert(root, 10);
  insert(root, 15);
  // 2) inorder 호출 → 정렬된 결과 확인
  inorder(root);
  // 3) search로 특정 값 찾기 테스트
  tnode *find_node = search(root, 10);
  if (find_node != NULL)
  {
    printf("\n%p %d", find_node,find_node -> key);
  }
  return 0;
}