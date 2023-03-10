queue CreateQ() {//创建队列
	queue Q = (queue)malloc(sizeof(struct Queue));//创建头节点/开辟空间
	Q->Next = NULL;//头节点空置
	return Q;
}

DataType back(queue Q) {//返回队列中的最后一个元素
	if (empty(Q)) return Error;//如果队列为空返回错误信息
	queue p = Q->Next;
	while (p->Next)p = p->Next;//找到最后一个元素的位置
	return p->Data;//返回最后一个元素
}

bool empty(queue Q) {//判断队列是否为空，如果队列空则返回真
	return Q->Next == NULL;
}

DataType front(queue Q) {//返回队列的第一个元素
	if (empty(Q)) return Error;//如果队列为空返回错误信息
	return  Q->Next->Data;//否则队列不为空直接返回第一个元素
}

void pop(queue Q) {//删除队列中的第一个元素
	if (empty(Q))return;//如果队列为空直接退出
	queue p = Q->Next;//删除第一个元素/结点
	Q->Next = p->Next;
	p->Next = NULL;
	free(p);//将已删除的结点的空间释放
}

void push(queue Q, DataType data) {//在队列末尾加入一个元素
	queue p = (queue)malloc(sizeof(struct Queue));//创建结点
	p->Next = NULL;//将准备插入的结点的尾指针指向空
	p->Data = data;//存入数据
	if (Q->Next) {//如果当前队列不为空
		queue q = Q->Next;
		while (q->Next)q = q->Next;
		q->Next = p;//插入结点
	}
	else Q->Next = p;//否则直接将要插入的结点作为第一个结点
}

int size(queue Q) {//返回队列中元素的个数
	int count = 0;//开一个变量计数
	queue p = Q->Next;
	while (p)p = p->Next, count++;//计数
	return count;//返回元素个数
}

void show(queue Q) {//额外添加，将队列所有元素输出，测试用
	if (empty(Q)) {//如果队列为空直接退出
		printf("队列为空\n");
		return;
	}
	queue p = Q->Next;//遍历输出
	while (p) {
		printf("%d ", p->Data);
		p = p->Next;
	}
	printf("\n");
}
