
    head = head->getnext();
    tmp->setnext(nullptr);
    --size;

}
void BagLancelotKnight::deletenode() {
    Node* tmp = head;
    head = head->getnext();
    tmp->setnext(nullptr);
    --size;

}
void BagDragonKnight::deletenode() {
    Node* tmp = head;
    head = head->getnext();
    tmp->setnext(nullptr);
    --size;

}