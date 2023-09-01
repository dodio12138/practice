import os

import discord
from discord.ext import commands

token = os.getenv("DISCORD_BOT_WIENER")

intents = discord.Intents.default()
intents.message_content = True

bot = commands.Bot(command_prefix=">", intents=intents)


@bot.command()
@commands.has_permissions(administrator=True)
async def synccommand(ctx):
    await bot.tree.sync()
    await ctx.send("同步完成")


@bot.hybrid_command()
async def ping(ctx):
    """乒乓球"""
    await ctx.send("pong")


@bot.hybrid_command()
async def add(ctx, a: int, b: int):
    """加法器"""
    await ctx.send(a + b)

class PlayView(discord.ui.View):
    @discord.ui.button(label="不玩了", style=discord.ButtonStyle.red)
    async def stop(self,interaction: discord.Integration, button: discord.ui.Button):
        await interaction.response.edit_message(content="好吧", view=None)

@bot.hybrid_command()
async def play(ctx):
    """小游戏"""
    await ctx.send("来吧！！！！", view=PlayView())

bot.run(token)
