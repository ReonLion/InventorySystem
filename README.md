#### ˵��
1.�ֿ⣨Inevntory���ɶ���������ʵ��  
2.���ϵı�����Backpack��������ʵ�֣�����һ���������Сһ�µ��б�������List������ʹ�ñ������ӵ���ʷ��¼��ÿ��ʹ�ñ����ϵ�ĳ������ʱ�����б�������ɾ���������id����push_back���id���Դ˱�֤�б�ĵ�һԪ�ؾ������δ��ʹ�õĸ���id  
3.�û���Ʒ����������PotionBase, WeaponBase, CoinBase�Ȼ���  
4.�û���Ʒ������ʹ�ù���ģʽ�����û��̳�ItemFactory�࣬��ʵ��Create()�ӿ�  
5.�û���Ʒ����Ʒ���(type)����Ʒid,��Ʒ���ƣ�name��Ψһ��ʶ  
6.Inventoy��Backpackֻ�����û���Ʒ��Ψһ��ʶ�����������������󣬾��������ʹ��ʱ��ItemFactory����Ψһ��ʶ������  
7.Inventoy��Backpack���ɶ�������ģʽʵ�ֶ��̰߳�ȫ
8.ʾ��������TestMainĿ¼  
9.ʾ��������Little HP Potion, Middle HP Potion, Big HP Potion�Զ��ϳ�Super HP Potion, MP PotionҲ��

#### Inventory
##### Syntax
```<language>
class Invetory
```
##### Remarks
Inventory����n��������������ÿһ����Ʒ�����Ӧһ������������������
##### Variables
##### Constructors
Name | Description
- | -
Inventory::GetInstance() | ����ʽ���������̰߳�ȫ
##### Destructors
|Name | Description |
| - | - |
|~Inventory() |  |
##### Functions
| Return | Name | Description |
| - | - | - |
| bool | Add(Item* p_item, int quantity) | ����quantity����item |
| bool | Remove(const Item & item, int quantity) | �Ƴ�quantity����item |
| bool | Exist(Item* p_item) | ���ظ�item�ĸ������������򷵻�0 |

#### Backpack
##### Syntax
```<language>
class Backpack
```
##### Remarks
Backpack��һ�����飬������n���ɴ�Ų�ʹ����Ʒ�ĸ��ӣ�nΪbackpack������
��һ���б���������Ÿ��ӵ�ʹ����ʷ
##### Variables
##### Constructors
| Name | Description |
| - | - |
| Backpack::GetInstance() | ����ʽ���������̰߳�ȫ |
##### Destructors
| Name | Description |
| - | - |
|~Backpack() |   |
##### Functions
| Return | Name | Description |
| - | - | - |
| void | SetInventory(Inventory* p_inventory) | ���룬�����뱳�������Ĳֿ� |
| void | SetItemManager(ItemFactory *p_itemFactory) | ���룬����Item�������� |
| bool | Pick(Item* p_item, int quantity) | ʰ���item�����뱳�����޿�λ�����ֿ� |
| bool | UseBox(int i) | ʹ�õ�i�������������Ʒ |
| bool | bool GetFromInventory(Item* p_item) | �Ӳֿ��л�ȡ��Ʒ�������� |
| void | MoveToInventory(Item* p_item) | ��item�ӱ������뵽�ֿ��У����ܷ������� |
| int | GetItemCount(Item* p_item) const | ����item�ڱ����еĸ�����û����Ϊ0 |

#### ItemFactory
##### Remarks
�����࣬�����û�ʵ����Create()��GetItemMixedStat()�ӿ�
