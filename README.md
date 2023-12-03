# Discord plugin for Unreal Engine 5

This plugin is designed for users of Unreal Engine 5. It will help you to create a discord presence for your game like this : 

![ExampleFeed](https://user-images.githubusercontent.com/47295080/147773806-fbaae57b-51e7-400f-a1a4-88a92bd77bd4.png)

# Credits
* LouisRaverdy (OP: https://github.com/LouisRaverdy/DiscordRPC)
 * Base plugin with Discord SDK intergation  
* Lewis/CusYaBasic (Me)
  * 5.3 update
  * Fix type error with TimeStamps
  * Added 'GetStartTimeStamp' function
  * Created 'DiscordGameInstance' class
  * Combind initial setup into one node 'SetDiscordPresence'
  * various minor fixes

## Installation

1) Dowload this repostory
2) Extract the repo
3) Copy all content to your plugin project (YourProject/Plugins)
4) Make sure you are register on [Discord developer website](https://discord.com/developers/applications  "Discord Developer Website")
5) Create your application and copy your Application ID
6) Open your project and enable the plugin

## Initialization 5.3

Version 5.3 has changed a little bit. it now has 'DiscordGameInstance' class which handles most of the logic for you; streamlining the process, making it much faster to get up and running.

1) You need to inherit your ```GameInstance``` class from ```DiscordGameInstance```:
![image](https://github.com/CusYaBasic/DiscordRPC/assets/86253238/f7d660af-3a57-4d08-978f-544fcf96c670)

1.B) If you're using unreals default ```GameInstance``` You'll need to create your own and inherit it from ```DiscordGameInstance``` then set your project to use that class in your project settings:
![image](https://github.com/CusYaBasic/DiscordRPC/assets/86253238/ec399748-829f-43a5-9178-a8169a9eb20f)
![image](https://github.com/CusYaBasic/DiscordRPC/assets/86253238/4b1b606b-65aa-42f1-bfe4-331b714cf6f5)
![image](https://github.com/CusYaBasic/DiscordRPC/assets/86253238/e5a3438a-33f2-4186-aa0f-7a7cf18d57ea)
(I called my instance ```I_GameInstance``` but just set it to whatever yours is called)
![image](https://github.com/CusYaBasic/DiscordRPC/assets/86253238/53fb7b6c-5097-43af-92d1-5f0dd3e72382)

2) Now that we are inheriting from ```DiscordGameInstance```, we can set out App IDs. Simpily override event ```init``` and call ```SetAppIDs``` while passing your IDs into the params.
> **Note :** AppID IS REQUIRED, Steam is OPTIONAL

![image](https://github.com/CusYaBasic/DiscordRPC/assets/86253238/bf1bee01-740f-4ca1-a002-468c765ce97e)

## Set Basic/All Presence

There are two ways of setting presence, ```SetBasicPresence``` and ```SetAllPresence```; Basic sets just the need to know features, lick icon, state, details and time elasped. Whereas - All sets all values that are in the ```DiscordPresence``` struct.
So anytime you need to update the presence info call any of these nodes:
![image](https://github.com/CusYaBasic/DiscordRPC/assets/86253238/f45dd0d6-ec05-49a7-a2f1-4c0df676d710)

## Set Discord Presence

Finally, once we have set our basic/all presence we can send it to the discord API using ```SetDiscordPresence```.
![image](https://github.com/CusYaBasic/DiscordRPC/assets/86253238/6f7526fd-44e9-45a7-b0b1-bd2ed387ff78)

```SetDiscordPresence``` also has a clear function build into it to clear the presence during runtime if you need to switch it when you switch maps/activiies
![image](https://github.com/CusYaBasic/DiscordRPC/assets/86253238/6cecf8c2-294b-46b7-8656-7297ec35ff6e)

## Deprecated

You'll no longer have to override event ```Shutdown``` as this is already done in code for your
![image](https://github.com/CusYaBasic/DiscordRPC/assets/86253238/543cfa32-c743-4d82-befa-423696cdb5c5)



## Initialization <-5.2 and below

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
