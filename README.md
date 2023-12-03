# Discord plugin for Unreal Engine 5

This plugin is designed for users of Unreal Engine 5. It will help you to create a discord presence for your game like this : 

![ExampleFeed](https://user-images.githubusercontent.com/47295080/147773806-fbaae57b-51e7-400f-a1a4-88a92bd77bd4.png)


## Installation

1) Dowload this repostory
2) Extract the repo
3) Copy all content to your plugin project (YourProject/Plugins)
4) Make sure you are register on [Discord developer website](https://discord.com/developers/applications  "Discord Developer Website")
5) Create your application and copy your Application ID
6) Open your project and enable the plugin

## Initialization

In order to establish a connection with the application you have created before and the discord app 
You need to create something like this in your **Game Instance**  : 

![InitDiscord](https://user-images.githubusercontent.com/47295080/147773538-c4ac76cd-2199-4a1a-af90-cc695d8c0386.png)

> **Note :** Make sure your Game Instance is defined as default in the Project Settings. (Project Settings -> Maps & Modes -> Game Instance Class)

For remove your presence when you exit the game you need to add this to your **Game Instance** :

![shutdown](https://user-images.githubusercontent.com/47295080/192113957-b7675e3f-161d-4d23-bb98-e5ce6f48a586.png)

## Nodes 

To update your presence for your game, you can use this code (read the image next to it to understand the fields of the node) : 

![SetPresenceDiscord](https://user-images.githubusercontent.com/47295080/147773549-6f106fda-835d-4cff-97f8-c220627b2dbf.png)

> **Note :** To use image in rich presence you need to upload them on your Discord developer game page (Rich Presence -> Art Assets)

### **More advanced documentation coming soon.**
