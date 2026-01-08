---
title: 'Créer un sensor custom dans Home Assistant provenant d'une valeur MQTT'
author: end2end
date: 2026-01-08
categories:
  - Home Assistant
  - Tutorial
tags:
  - Home Assistant
  - Tutorial
---

# Contexte

J'utilise une serrure intelligente à la maison. C'est le modèle [916 SmartCode Traditional Electronic Deadbolt with Zigbee Technology](https://www.kwikset.com/products/detail/916-smartcode-traditional-electronic-deadbolt-with-zigbee-technology) par Kwikset.

Elle est disponible dans Home Assistant. Je peux donc lui envoyer des commandes telles que "Barre-toi" ou "Débarre-toi". Je peux aussi recevoir son état courant pour savoir si la porte est actuellement barrée ou pas.

La serrure communique en utilisant le protocole Zigbee. Pour être disponible dans Home Assistant, j'utilise Zigbee2Mqtt qui permet d'exposer des appareils Zigbee dans Home Assistant via un serveur MQTT.
Zigbee2Mqtt détecte la serrure en tant qu'un [SmartCode 10 Touch par Weiser](https://www.zigbee2mqtt.io/devices/9GED21500-005.html).

La communication bidirectionelle se fait de la façon suivante:
```
Serrure <--> Zigbee 3.0 <--> Zigbee2Mqtt <--> Serveur MQTT <--> Réseau Ethernet/Wifi <--> Home Assisant
```

# Problème

Malheureusement, il semble que Zigbee2Mqtt n'expose pas tous les états de la serrure dans Home Assitant.

Par exemple, la serrure peut-être dans un des états suivants:
1. `locked`
2. `unlocked`
3. `not_fully_locked`

Mais dans Home Assistant, l'état de la serrure sera exposée comme `LOCK` ou `UNLOCK`. Dans le 3e cas, Home Assistant affiche `UNLOCK`.

Il arrive parfois que la porte n'est pas bien fermée et donc la serrure n'est pas bien enclanchée. Avec la configuration de base dans Home Assistant, ce n'est malheureusement pas possible de pouvoir créé une automatisation lorsque cela se produit.

# Solution

Créer un sensor custom dans Home Assistant provenant d'une valeur MQTT !

Il est possible de créé une entité sensor personnalisée dans Home Assistant afin d'exposer la chaîne de charactère qui provient directement de l'appareil zigbee.

L'état de la serrure (`locked`, `unlocked` ou `not_fully_locked`) est exposée dans MQTT via le topic suivant:  
`zigbee2mqtt/serrure_porte_avant`.

Le payload est de type json et ressemble à ceci:
```json
{
  "action_source_name": null,
  "action_user": null,
  "auto_relock_time": null,
  "battery": 70,
  "linkquality": 255,
  "lock_state": "not_fully_locked",
  "pin_code": null,
  "sound_volume": null,
  "state": "UNLOCK",
  "users": {
    // ...
  }
}
```

Il est possible d'exposer la propriété json `lock_state` dans Home Assistant comme une entité indépendante. 

Pour ce faire, il faut modifier directement le fichier `configuration.yaml` de la façon suivante:
```yaml
# Custom integration for Serrure-Porte-Avant
# https://www.home-assistant.io/integrations/sensor.mqtt/
mqtt:
  sensor:
    - name: "My Serrure Porte Avant Advanced Lock state"
      state_topic: "zigbee2mqtt/serrure_porte_avant"
      value_template: "{{ value_json.lock_state }}"
```

> Note:  
Après la modification, il faut redémarer Home Assistant pour que le changement soit disponible.

# Valider

Vous pouvez ensuite valider que l'état "réel" de la serrure est maintenant disponible via une entité.

Pour ce faire, aller dans le menu [_Developper tools_, onglet _States_](http://homeassistant.local:8123/developer-tools/state) et faite une recherche pour `my serrure`.
Vous devriez voir l'entité `sensor.my_serrure_porte_avant_advanced_lock_state` avec le State `locked`, `unlocked` ou `not_fully_locked`.
