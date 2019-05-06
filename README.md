#### 说明
1.仓库（Inevntory）由二叉搜索树实现  
2.身上的背包（Backpack）由数组实现，并有一个和数组大小一致的列表容器（List）保存使用背包格子的历史纪录，每次使用背包上的某个格子时，从列表容器中删除这个格子id，再push_back这个id，以此保证列表的第一元素就是最久未被使用的格子id  
3.用户物品必须派生自PotionBase, WeaponBase, CoinBase等基类  
4.用户物品的生成使用工厂模式，需用户继承ItemFactory类，并实现Create()接口  
5.用户物品由物品类别(type)，物品id,物品名称（name）唯一标识  
6.Inventoy和Backpack只保存用户物品的唯一标识符，并不保存具体对象，具体对象在使用时由ItemFactory根据唯一标识符生成  
7.Inventoy和Backpack借由饿汉单例模式实现多线程安全
8.示例程序在TestMain目录  
9.示例程序中Little HP Potion, Middle HP Potion, Big HP Potion自动合成Super HP Potion, MP Potion也是

#### Inventory
##### Syntax
```<language>
class Invetory
```
##### Remarks
Inventory具有n个二叉搜索树（每一个物品种类对应一棵树），无容量限制
##### Variables
##### Constructors
Name | Description
- | -
Inventory::GetInstance() | 饿汉式单例，多线程安全
##### Destructors
|Name | Description |
| - | - |
|~Inventory() |  |
##### Functions
| Return | Name | Description |
| - | - | - |
| bool | Add(Item* p_item, int quantity) | 加入quantity个该item |
| bool | Remove(const Item & item, int quantity) | 移除quantity个该item |
| bool | Exist(Item* p_item) | 返回该item的个数，不存在则返回0 |

#### Backpack
##### Syntax
```<language>
class Backpack
```
##### Remarks
Backpack有一个数组，代表了n个可存放并使用物品的格子（n为backpack容量）
有一个列表容器，存放格子的使用历史
##### Variables
##### Constructors
| Name | Description |
| - | - |
| Backpack::GetInstance() | 饿汉式单例，多线程安全 |
##### Destructors
| Name | Description |
| - | - |
|~Backpack() |   |
##### Functions
| Return | Name | Description |
| - | - | - |
| void | SetInventory(Inventory* p_inventory) | 必须，设置与背包关联的仓库 |
| void | SetItemManager(ItemFactory *p_itemFactory) | 必须，设置Item生产工厂 |
| bool | Pick(Item* p_item, int quantity) | 拾起该item，放入背包，无空位则放入仓库 |
| bool | UseBox(int i) | 使用第i个格子里面的物品 |
| bool | bool GetFromInventory(Item* p_item) | 从仓库中获取物品到背包中 |
| void | MoveToInventory(Item* p_item) | 将item从背包移入到仓库中，可能发生交换 |
| int | GetItemCount(Item* p_item) const | 返回item在背包中的个数，没有则为0 |

#### ItemFactory
##### Remarks
抽象类，需由用户实现其Create()和GetItemMixedStat()接口
