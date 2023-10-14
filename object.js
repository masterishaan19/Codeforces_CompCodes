class Product {
    // title = 'DEFAULT';
    // imageUrl;
    // description;
    // price;

    constructor(title, image, desc, price) {
      this.title = title;
      this.imageUrl = image;
      this.description = desc;
      this.price = price;
    }
  }

  class ElementAttribute {
    constructor(attrName, attrValue) {
      this.name = attrName;
      this.value = attrValue;
    }
  }

  class Component {
    constructor(renderHookId, shouldRender = true) {
      this.hookId = renderHookId;
      if(shouldRender){
        this.render();
      }

    }

    render(){

    }

    createRootElement(tag, cssClasses, attributes) {
      const rootElement = document.createElement(tag);
      if (cssClasses) {
        rootElement.className = cssClasses;
      }
      if (attributes && attributes.length > 0) {
        for (const attr of attributes) {
          rootElement.setAttribute(attr.name, attr.value);
        }
      }
      document.getElementById(this.hookId).append(rootElement);
      return rootElement;
    }
  }

  class ShoppingCart extends Component {
    items = [];

    set cartItems(value) {
      this.items = value;
      this.totalOutput.innerHTML = `<h2>Total: \$${this.totalAmount.toFixed(2)}</h2>`;
    }

    get totalAmount() {
      const sum = this.items.reduce(
        (prevValue, curItem) => prevValue + curItem.price,
        0
      );
      return sum;
    }

    constructor(renderHookId) {
      super(renderHookId,false);
        this.orderProducts = () => {
            console.log('Ordering...');
            console.log(this.items);
        }
        this.render();
    }

    addProduct(product) {
      const updatedItems = [...this.items];
      updatedItems.push(product);
      this.cartItems = updatedItems;
    }



    render() {
      const cartEl = this.createRootElement('section', 'cart');
      cartEl.innerHTML = `
        <h2>Total: \$${0}</h2>
        <button>Order Now!</button>
      `;
      const orderButton = cartEl.querySelector('button');
      orderButton.addEventListener('click',this.orderProducts);
      this.totalOutput = cartEl.querySelector('h2');
    }
  }

  class ProductItem extends Component {
    constructor(product,renderHookId) {
        super(renderHookId,false);
        this.product = product;
        this.render();
    }

    addToCart() {
      App.addProductToCart(this.product);
    }

    render() {
      const prodEl = this.createRootElement('li','product-item');
      prodEl.innerHTML = `
          <div>
            <img src="${this.product.imageUrl}" alt="${this.product.title}" >
            <div class="product-item__content">
              <h2>${this.product.title}</h2>
              <h3>\$${this.product.price}</h3>
              <p>${this.product.description}</p>
              <button>Add to Cart</button>
            </div>
          </div>
        `;
      const addCartButton = prodEl.querySelector('button');
      addCartButton.addEventListener('click', this.addToCart.bind(this));
    }
  }

  class ProductList extends Component{
    products = [];

    constructor(renderHookId) {
        super(renderHookId);
        this.fetchProducts();
    }

    fetchProducts(){
        this.products = [
            new Product('A pillow',
            'https://5.imimg.com/data5/SELLER/Default/2023/8/337460979/UE/TA/OA/37215830/heart-shape-sublimation-pillow-1000x1000.jpg',
            'A simple Pillow', 69.69 ),

            new Product('A Carpet',
            'https://assets.ajio.com/medias/sys_master/root/20230906/7jpW/64f8e8f8afa4cf41f5c9ea49/-1117Wx1400H-461341351-blue-MODEL.jpg',
            'A Simple Carpet you may like.',911),

            new Product('A Poster',
            'https://wallpapers.com/images/high/naruto-kurama-nine-tails-chakra-mode-f261kq0k53c49unj.webp',
            'A poster with Naruto on it in :: SAGE WITH NINE TAIL MODE ::',143),
            new Product('Key Chain',
            'https://5.imimg.com/data5/ZA/UB/DL/SELLER-38579979/marvel-avengers-super-hero-key-chains-500x500.JPG',
            'Avengers Assemble!!',11.11)
            /*{  // another way to represent the members without using the classes.....
                 title : 'A pillow',
                 imageUrl : 'https://5.imimg.com/data5/SELLER/Default/2023/8/337460979/UE/TA/OA/37215830/heart-shape-sublimation-pillow-1000x1000.jpg',
                 price : 69.69,
                 description : 'A simple Pillow'
             },
             {
                 title : 'A Carpet',
                 imageUrl : 'https://assets.ajio.com/medias/sys_master/root/20230906/7jpW/64f8e8f8afa4cf41f5c9ea49/-1117Wx1400H-461341351-blue-MODEL.jpg',
                 price : 911.911,
                 description : 'A Simple Carpet you may like.'
             }*/
            ];
            this.renderProducts();
    }

    renderProducts(){
        for (const prod of this.products) {
            new ProductItem(prod,'prod-list');
          }
    }

    render() {
      const prodList = this.createRootElement('ul','product-list',
      [new ElementAttribute('id','prod-list')
    ]);
    if(this.products && this.products.length > 0){
        this.renderProducts();
    }
  }
}

  class Shop{
    constructor(){
        this.render();
    }

    render() {
      this.cart = new ShoppingCart('app');
      new ProductList('app');
    }
  }

  class App {
    static cart;

    static init() {
      const shop = new Shop();
      this.cart = shop.cart;
    }

    static addProductToCart(product) {
      this.cart.addProduct(product);
    }
  }

  App.init();
