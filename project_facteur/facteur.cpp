






List* creer_list(QString path)
{

    List* list = new List;
    list->head = NULL;
    list->path = path;
    list->size = 0;
    qDebug() << " -- La list était creer -- \n";
    return list;
}

Produit* creer_produit(QString id, QString libelle, QString prix, QString qte, QString date)
{
    Produit* produit = new Produit;
    produit->id.resize(id.size(), ' ');
    produit->id = id;

    produit->libelle.resize(libelle.size(), ' ');
    produit->libelle = libelle;

    produit->prix.resize(prix.size(), ' ');
    produit->prix = prix;

    produit->qte.resize(qte.size(), ' ');
    produit->qte = qte;

    produit->date.resize(date.size(), ' ');
    produit->date = date;
    produit->next = NULL;

    return produit;
}


void afficher(List* list)
{
    if(list->head == NULL)
    {
        return;
    }
    Produit* t = list->head;
    while(t != NULL)
    {
        qDebug() << t->id << t->libelle << t->prix << t->qte << t->date << ":";
        t = t->next;
    }

}
